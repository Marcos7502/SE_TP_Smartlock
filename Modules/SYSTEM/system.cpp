#include "mbed.h"
#include "arm_book_lib.h"
#include <SPI.h>
#include "string.h"
#include "system.h"
#include "access_keys.h"
#include "keypad.h"
#include "UART_comm.h"
#include "RFID_reader.h"
#include "motors.h"
#include "speaker.h"
#include "global_defines.h"
#include "MQTT.h"


door_state main_door_state = DOOR_CLOSED;
door_state last_door_state = NONE;
access_state access_attempt;

char* rfid_content = nullptr;
char* keypad_sequence_read = nullptr;
char last_rfid_read[20]="";

bool save_id = false;
bool door_left_open = false;
bool force_block_door = false;

int blinks_counter = 0;
int time_door_open;

Timer DoorOpenTimer;
Timer BlinkingLedTimer; //No es el mejor uso de un timer pero no se me ocurre otra forma


PinName  keypadRowPins[KEYPAD_NUMBER_OF_ROWS] = {PB_3, PB_5, PC_7, PA_15};
PinName  keypadColPins[KEYPAD_NUMBER_OF_COLS]  = {PB_12, PB_13, PB_15, PC_6};


DigitalIn MagnetSensor(PIN_MAGNET_SENSOR_1);
DigitalOut DoorBlockedLed(PIN_LED_DOOR_BLOCKED);
DigitalOut DoorOpenLed(PIN_LED_DOOR_OPEN);

static Keypad KeypadDoor(keypadRowPins,keypadColPins);
static Motor LockMotor(PIN_MOTOR_LOCK);
static Speaker SpeakerDoor(PIN_SPEAKER);
static MQTT Mqtt(PIN_MQTT_TX, PIN_MQTT_RX, MQTT_BAUDRATE, PIN_MQTT_LED);


InterruptIn  DoorBlockButton(PIN_BUTTON_DOOR_BLOCK);

// Module: initialization -------------------------
void system_init(){
    set_time(1256729737);
 
    rfid_content = nullptr;

    MagnetSensor.mode(PullDown);

    DoorOpenTimer.reset();
    DoorOpenTimer.stop();

    BlinkingLedTimer.reset();
    BlinkingLedTimer.stop();
    
    RFID_reader_init();

    DoorBlockButton.mode(PullDown);
    DoorBlockButton.rise(&force_door_close);
    char status_code_init[2]; // Size 3 to include the null terminator
    status_code_init[0] = '2';
    status_code_init[1] = '\n';
    

    Mqtt.SendStatus(status_code_init);


}

void system_update(){
    process_mqtt();
    if(force_block_door){
        force_door_close();
    }
    switch(main_door_state){
        case DOOR_CLOSED:
            main_door_state = system_door_closed_update();           
            break;
        
        case DOOR_OPENING:
            main_door_state = system_door_opening_update();
            break;
        
        case DOOR_OPEN:
            main_door_state = system_door_open_update();
            break;

        case DOOR_CLOSING:
            main_door_state = system_door_closing_update();         
            break;
        case NONE:
            break;
    }
 
    
}



door_state system_door_closed_update(){
    rfid_content = RFID_read();
    if(rfid_content!= nullptr){
        strncpy(last_rfid_read,rfid_content,20);
    }
    
    
    UARTShowRFID(rfid_content); 
    save_id = UART_get_save_id_input();
    if(save_id == true){
        access_keys_save_id(last_rfid_read);
        save_id = false;
    }
    keypad_sequence_read = KeypadDoor.get_code();
    if(KeypadDoor.button_pressed()==true){
        SpeakerDoor.play_note_button();
    }
    access_attempt = access_attempt_update(rfid_content,keypad_sequence_read);
    
    if(access_attempt == ACCESS_DENIED){
        blinks_counter = WRONG_ID_BLINKS;
        BlinkingLedTimer.start();
        UART_send_wrong_id_message();
        SpeakerDoor.play_incorrectcode();
                                
    }
    
    if(blinks_counter != 0){
        blink_leds();
    }
    else{
        DoorBlockedLed = ON;
        DoorOpenLed = OFF;
    }
    if(access_attempt == ACCESS_GRANTED){
        return DOOR_OPENING;
    }
    SpeakerDoor.update();
    return DOOR_CLOSED;
             
                
}
door_state system_door_closing_update(){
    if(MagnetSensor == OFF){
        DoorOpenLed = ON;
        if(door_left_open == false){
            blinks_counter = -1;
            BlinkingLedTimer.start();
            door_left_open = true;
            DoorOpenTimer.start();
            DoorOpenTimer.reset();
            UART_send_door_left_open_message(door_left_open);
            SpeakerDoor.play_alarm();   
        }
        if(door_left_open == true){
            blink_leds();
            SpeakerDoor.alarm_update();
        }                                        
            
    }

    if(MagnetSensor == ON){
        blinks_counter = 0;
        if(door_left_open == true){
            door_left_open = false;
            UART_send_door_left_open_message(door_left_open);
        }
        DoorOpenTimer.stop();
        DoorOpenTimer.reset();
        //activar cerradura
        LockMotor.set_position(MOTOR_POS_LOCKED);
       
        return DOOR_CLOSED;
    }
    SpeakerDoor.update();
    return DOOR_CLOSING;
    
}
door_state system_door_open_update(){
    DoorBlockedLed = OFF;
    DoorOpenLed = ON;

    time_door_open = DoorOpenTimer.read_ms();

    if(time_door_open>=TIMEOUT_DOOR_OPEN){
        return DOOR_CLOSING; 
    }
    SpeakerDoor.update();
    return DOOR_OPEN;
    
}
door_state system_door_opening_update(){
    UART_send_access_message(rfid_content,keypad_sequence_read);
    DoorOpenTimer.start();
    
 
    LockMotor.set_position(MOTOR_POS_OPEN);
    SpeakerDoor.play_music_welcome();
    SpeakerDoor.update();
    return DOOR_OPEN;
}




// Module: Blink Leds (wrong id, door open)  -------------------------
void blink_leds(){
    if(blinks_counter != 0){
        
        if(BlinkingLedTimer.read_ms()>=LED_BLINK_INTERVAL){
            DoorBlockedLed = !DoorBlockedLed;
            BlinkingLedTimer.reset();
            if(blinks_counter > 0){
                blinks_counter = blinks_counter - 1;
            }
        }
        
    }
    if(blinks_counter == 0){
        BlinkingLedTimer.reset();
        BlinkingLedTimer.stop();
    }
    
}
void force_door_close(){
    if(MagnetSensor == OFF){
        main_door_state = DOOR_CLOSING; 
    }
    else{
        main_door_state = DOOR_CLOSED; 
    }
    
}

void process_mqtt(){
    Mqtt.keepAlive();
    if(last_door_state != main_door_state){
        char status_code[2];
        switch(main_door_state){
            case DOOR_CLOSED:
                status_code[0]='2';     
                break;
        
            case DOOR_OPENING:
                status_code[0]='1';  
                break;
            
            case DOOR_OPEN:
                status_code[0]='1'; 
                break;

            case DOOR_CLOSING:
                status_code[0]='3';  
                break;

            case NONE:
                break;

        }
       status_code[1]='\n'; 

       Mqtt.SendStatus(status_code);

       last_door_state = main_door_state;
        
    }
    
    MQTTMessage mqtt_msg =  Mqtt.receive();
    if(mqtt_msg.received){
        if(strcmp(mqtt_msg.topic, "Smartlock/1/Control" ) == 0){
            if(strcmp(mqtt_msg.message, "force_block_true")==0){
                
                force_block_door = true;
            }
            else if(strcmp(mqtt_msg.message, "force_block_false")==0){
                force_block_door = false;
            }
            else if(strcmp(mqtt_msg.message, "manual_open_true")==0){
                main_door_state=DOOR_OPENING;
            }
        }
        // else if(strcmp(mqtt_msg.topic, "Smartlock/1/Security" ) == 0){
            
        // }

    }

}