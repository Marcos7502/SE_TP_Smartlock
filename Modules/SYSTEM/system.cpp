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




access_state access_attempt;

char* rfid_content = nullptr;
char* keypad_sequence_read = nullptr;
char last_rfid_read[20]="";

bool save_id = false;
bool doorleftopen = false;

int blinks_counter = 0;
int time_door_open;
Timer DoorOpenTimer;
Timer BlinkingLedTimer; //No es el mejor uso de un timer pero no se me ocurre otra forma


PinName  keypadRowPins[KEYPAD_NUMBER_OF_ROWS] = {PB_3, PB_5, PC_7, PA_15};
PinName  keypadColPins[KEYPAD_NUMBER_OF_COLS]  = {PB_12, PB_13, PB_15, PC_6};



DigitalIn doorblockbutton(PIN_BUTTON_DOOR_BLOCK);
DigitalIn magnetsensor(PIN_MAGNET_SENSOR_1);

DigitalOut doorblockedLED(PIN_LED_DOOR_BLOCKED);
DigitalOut dooropenLED(PIN_LED_DOOR_OPEN);

Keypad Keypad_door(keypadRowPins,keypadColPins);

Motor lock_motor(PIN_MOTOR_LOCK);
Speaker speaker(PIN_SPEAKER);

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
    keypad_sequence_read = Keypad_door.get_code();
    if(Keypad_door.button_pressed()==true){
        speaker.play_note_button();
    }
    access_attempt = access_attempt_update(rfid_content,keypad_sequence_read);
    
    if(access_attempt == ACCESS_DENIED){
        blinks_counter = WRONG_ID_BLINKS;
        BlinkingLedTimer.start();
        UART_send_wrong_id_message();
                                
    }
    
    if(blinks_counter != 0){
        blink_leds();
    }
    else{
        doorblockedLED = ON;
        dooropenLED = OFF;
    }
    if(access_attempt == ACCESS_GRANTED){
        return DOOR_OPENING;
    }
    speaker.update();
    return DOOR_CLOSED;
             
                
}

door_state system_door_closing_update(){
    if(magnetsensor == OFF){
        dooropenLED = ON;
        if(doorleftopen == false){
            blinks_counter = -1;
            BlinkingLedTimer.start();
            doorleftopen = true;
            DoorOpenTimer.start();
            DoorOpenTimer.reset();
            UART_send_door_left_open_message(doorleftopen);
            speaker.play_alarm();   
        }
        if(doorleftopen == true){
            blink_leds();
            speaker.alarm_update();
        }                                        
            
    }

    if(magnetsensor == ON){
        blinks_counter = 0;
        if(doorleftopen == true){
            doorleftopen = false;
            UART_send_door_left_open_message(doorleftopen);
        }
        DoorOpenTimer.stop();
        DoorOpenTimer.reset();
        //activar cerradura
        lock_motor.set_position(MOTOR_POS_LOCKED);
        lock_motor.stop();
        return DOOR_CLOSED;
    }
    speaker.update();
    return DOOR_CLOSING;
    
}
door_state system_door_open_update(){
    doorblockedLED = OFF;
    dooropenLED = ON;

    time_door_open = DoorOpenTimer.read_ms();
    if(doorblockbutton.read() == ON){
        return DOOR_CLOSING; 
    }
    if(time_door_open>=TIMEOUT_DOOR_OPEN){
        return DOOR_CLOSING; 
    }
    speaker.update();
    return DOOR_OPEN;
    
}
door_state system_door_opening_update(){
    UART_send_access_message(rfid_content,keypad_sequence_read);
    DoorOpenTimer.start();
    
    if(doorblockbutton.read() == ON){
        return DOOR_CLOSING; 
    }
    lock_motor.set_position(MOTOR_POS_OPEN);
    speaker.play_music_welcome();
    speaker.update();
    return DOOR_OPEN;
}
// Module: initialization -------------------------
void system_init(){
    set_time(1256729737);
 
    rfid_content = nullptr;

    doorblockbutton.mode(PullDown);
    magnetsensor.mode(PullDown);

    DoorOpenTimer.reset();
    DoorOpenTimer.stop();

    BlinkingLedTimer.reset();
    BlinkingLedTimer.stop();
    
    RFID_reader_init();


}

// Module: Blink Leds (wrong id, door open)  -------------------------
void blink_leds(){
    if(blinks_counter != 0){
        
        if(BlinkingLedTimer.read_ms()>=LED_BLINK_INTERVAL){
            doorblockedLED = !doorblockedLED;
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