#include "mbed.h"
#include "arm_book_lib.h"
#include "global_defines.h"
#include "keypad.h"
#include "UART_comm.h"
#include "RFID_reader.h"

#include <SPI.h> 

/* MFRC522.h - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT.
Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
Created by Miguel Balboa (circuitito.com), Jan, 2012.
Rewritten by Soren Thing Andersen (access.thing.dk), fall of 2013 (Translation to English, refactored, comments, anti collision, cascade levels.)
Ported to mbed by Martin Olejar, Dec, 2013
Link: https://os.mbed.com/teams/Project5_Software/code/RFID-RC522/docs/tip/MFRC522_8h_source.html
*/

#include <string.h>


char allowed_id[20] = "";  // ID permitido
char reading_rfid[20] = "";
char* rfid_content = nullptr;



char keyReleased = '\0';
int key_counter = 0;
char keypad_code[4] = {'1' ,'2' ,'3' ,'4'}; 
char keypad_sequence_read[4] = {'0','0','0','0'};

int blinks_counter = 0;
int time_door_open;
bool wrong_id = false;
bool save_id = false;
bool doorleftopen = false;

enum Door{
    DOOR_OPENING,
    DOOR_OPEN,
    DOOR_CLOSING,
    DOOR_CLOSED
};


Door door_state;

DigitalIn doorblockbutton(PIN_BUTTON_DOOR_BLOCK);
DigitalIn magnetsensor(PIN_MAGNET_SENSOR_1);

DigitalOut doorblockedLED(PIN_LED_DOOR_BLOCKED);
DigitalOut dooropenLED(PIN_LED_DOOR_OPEN);


void system_init();

void compare_content_read_rfid_to_keys();
void blink_leds();



Timer DoorOpenTimer;
Timer CodeTimeoutTimer;
Timer BlinkingLedTimer; //No es el mejor uso de un timer pero no se me ocurre otra forma


PinName  keypadRowPins[KEYPAD_NUMBER_OF_ROWS] = {PB_3, PB_5, PC_7, PA_15};
PinName  keypadColPins[KEYPAD_NUMBER_OF_COLS]  = {PB_12, PB_13, PB_15, PC_6};

Keypad Keypad_door(keypadRowPins,keypadColPins);

int main(){   
    system_init();
    while (true) {

        switch(door_state){
            case DOOR_CLOSED:
                
                
                rfid_content = RFID_read();
                if(rfid_content != nullptr){
                    strncpy(reading_rfid, rfid_content,sizeof(reading_rfid) );       
                }
                UARTShowRFID(rfid_content); 
                save_id = UART_get_save_id_input();
                
                if(save_id == true && rfid_content != nullptr){
                    strncpy(allowed_id, rfid_content,sizeof(allowed_id));
                    save_id = false;
                    UART_notify_ID_was_saved();
                }
                if(rfid_content != nullptr){
                    compare_content_read_rfid_to_keys();
                }
                keyReleased = Keypad_door.matrixKeypadUpdate();
                if(keyReleased != '\0'){
                    // DEBUGGING
                    // UsbBuffer[0] = keyReleased;
                    // UsbBuffer[1] = '\r';
                    // UsbBuffer[2] = '\n';
                    // UARTUsb.write( "Read Key:", 9 );
                    // UARTUsb.write( UsbBuffer , 3);
                    if(key_counter == 0){
                        CodeTimeoutTimer.start();
                    }
                    keypad_sequence_read[key_counter] = keyReleased;

                    if(key_counter == 3){
                        CodeTimeoutTimer.stop();
                        CodeTimeoutTimer.reset();
                        key_counter = 0;

                        for (int i = 0; i < 4; i++) {
                            if (keypad_code[i] != keypad_sequence_read[i]) {
                                wrong_id = true;
                                break;
                            }
                        }
                        if(wrong_id == false){
                            door_state = DOOR_OPENING;
                        }
                    }
                    else{
                        key_counter += 1;
                    }

                }
                if((door_state!= DOOR_OPENING) && (CodeTimeoutTimer.read_ms() > TIMEOUT_CODE)){
                    key_counter = 0;
                    CodeTimeoutTimer.stop();
                    CodeTimeoutTimer.reset();
                    wrong_id =true;
                } 
                if(wrong_id == true){
                    blinks_counter = WRONG_ID_BLINKS;
                    BlinkingLedTimer.start();
                    UART_send_wrong_id_message();
                    
                    wrong_id = false;
                        
                }
                   
                
                if(blinks_counter != 0){
                    blink_leds();
                }
                else{
                    doorblockedLED = ON;
                    dooropenLED = OFF;
                }
                
                
                break;
            case DOOR_OPENING:
                UART_send_access_message(rfid_content,keypad_code);
                DoorOpenTimer.start();
                door_state = DOOR_OPEN;
                if(doorblockbutton.read() == ON){
                    door_state = DOOR_CLOSING; 
                }
                break;
            case DOOR_OPEN:
                doorblockedLED = OFF;
                dooropenLED = ON;

                time_door_open = DoorOpenTimer.read_ms();
                if(doorblockbutton.read() == ON){
                    door_state = DOOR_CLOSING; 
                }
                if(time_door_open>=TIMEOUT_DOOR_OPEN){
                    door_state = DOOR_CLOSING; 
                }
                break;
            case DOOR_CLOSING:
                         
                if(magnetsensor == OFF){
                    dooropenLED = ON;
                    if(doorleftopen == false){
                        blinks_counter = -1;
                        BlinkingLedTimer.start();
                        doorleftopen = true;
                        DoorOpenTimer.start();
                        DoorOpenTimer.reset();
                        UART_send_door_left_open_message(doorleftopen);
                        
                    }
                    if(doorleftopen == true){
                        blink_leds();
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
                    door_state = DOOR_CLOSED;
                }
                break;
        }
   
    }
}
// Module: initialization -------------------------
void system_init(){
    set_time(1256729737);
    key_counter = 0;
    rfid_content = nullptr;

    doorblockbutton.mode(PullDown);
    magnetsensor.mode(PullDown);

    CodeTimeoutTimer.reset();
    CodeTimeoutTimer.stop();

    DoorOpenTimer.reset();
    DoorOpenTimer.stop();

    BlinkingLedTimer.reset();
    BlinkingLedTimer.stop();
    
    RFID_reader_init();

    door_state=DOOR_CLOSED;

}





// Module: RFID content to keys comparison  -------------------------
void compare_content_read_rfid_to_keys(){
    
    if(strcmp(reading_rfid, allowed_id) == 0){
    door_state = DOOR_OPENING;
    wrong_id = false;
    }
    if(strcmp(reading_rfid, allowed_id) != 0){
        wrong_id = true;
    }
    
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

