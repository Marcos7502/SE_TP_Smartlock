#include "mbed.h"
#include "arm_book_lib.h"
#include "global_defines.h" 
#include "MFRC522.h" 
/* MFRC522.h - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT.
Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
Created by Miguel Balboa (circuitito.com), Jan, 2012.
Rewritten by Soren Thing Andersen (access.thing.dk), fall of 2013 (Translation to English, refactored, comments, anti collision, cascade levels.)
Ported to mbed by Martin Olejar, Dec, 2013
Link: https://os.mbed.com/teams/Project5_Software/code/RFID-RC522/docs/tip/MFRC522_8h_source.html
*/
#include <string.h>
#include <SPI.h>
#include "keypad/keypad.h"

char allowed_id[20] = "";  // ID permitido
char reading_rfid[20] = "";
char* rfid_content = nullptr;

char keyReleased = '\0';
int key_counter = 0;
char keypad_code[4] = {'1' ,'2' ,'3' ,'4'}; 
char keypad_sequence_read[4] = {'0','0','0','0'};

int time_door_open;
bool wrong_id = false;
bool save_id = false;

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


UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
MFRC522    RFID_READER   (PIN_RFID_MOSI, PIN_RFID_MISO, PIN_RFID_SCK, PIN_RFID_CS, PIN_RFID_RESET);


void system_init();
void uartShowRFID();
char* RFID_read(MFRC522& rfid_reader);
void compare_content_read_rfid_to_keys();

Timer doorTimer;
Timer CodeTimeoutTimer;

PinName  keypadRowPins[KEYPAD_NUMBER_OF_ROWS] = {PB_3, PB_5, PC_7, PA_15};
PinName  keypadColPins[KEYPAD_NUMBER_OF_COLS]  = {PB_12, PB_13, PB_15, PC_6};

Keypad Keypad_door(keypadRowPins,keypadColPins);

int main(){   
    system_init();

    while (true) {
        time_door_open = doorTimer.read_ms();
        if( (time_door_open!=0) && (time_door_open < 10000)){
            if(doorblockbutton.read() == ON){
                door_state = DOOR_CLOSING; 
            }
        }
        else{
            if(time_door_open>=10000){
                
                door_state = DOOR_CLOSING; 
            }
            rfid_content = RFID_read(RFID_READER); 
            if(rfid_content != nullptr){
                strncpy(reading_rfid, rfid_content,sizeof(reading_rfid) );
            }
            uartShowRFID();
            if(save_id == true && rfid_content != nullptr){
                strncpy(allowed_id, rfid_content,sizeof(allowed_id));
                save_id = false;
                uartUsb.write("Saved ID\r\n",8);
            }
            if(rfid_content != nullptr){
                compare_content_read_rfid_to_keys();
            }
                                   
            if(door_state != DOOR_OPENING & wrong_id == false){
                keyReleased = Keypad_door.matrixKeypadUpdate();
                if(keyReleased != '\0'){
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
                if(CodeTimeoutTimer.read_ms() > 15000){
                    key_counter = 0;
                    CodeTimeoutTimer.stop();
                    CodeTimeoutTimer.reset();
                    wrong_id =true;
                }
            }
            if(wrong_id == true){
                door_state = DOOR_CLOSING;
                wrong_id = false;
            }
            
            if(doorblockbutton.read() == ON){
                door_state = DOOR_CLOSING; 
            }
        }
        if(door_state == DOOR_OPEN){
            door_state = DOOR_OPEN;
        }

        if(door_state == DOOR_OPEN){
            doorblockedLED = OFF;
            dooropenLED = ON;
        }
        if(door_state == DOOR_CLOSING){
            doorTimer.stop();
            doorTimer.reset();
            if(magnetsensor == ON){
                door_state = DOOR_CLOSED;
            }
            
            
        }
        if(door_state == DOOR_CLOSED){
            doorblockedLED = ON;
            dooropenLED = OFF;
        }
        
    }
}
// Module: initialization -------------------------
void system_init(){
    doorblockbutton.mode(PullDown);
    magnetsensor.mode(PullDown);

    RFID_READER.PCD_Init();

    doorTimer.reset();

    door_state=DOOR_CLOSED;

}


// Module: uart communications  -------------------------
void uartShowRFID(){
    char receivedChar = '\0';
    
    if(rfid_content != nullptr){
        uartUsb.write( "Read ID\r\n", 9 );
        uartUsb.write( rfid_content, strlen(rfid_content) );
        uartUsb.write( "To save Tag press 1\r\n", 23 );
    }
    if( uartUsb.readable() ){
       uartUsb.read( &receivedChar, 1 );
       if(receivedChar == '1'){
            save_id = true;
            uartUsb.write("Recieved char\r\n",15);
        }
    }
    
}
// Module: RFID reader  -------------------------
char* RFID_read(MFRC522& rfid_reader){
   static char id[20] = ""; // Buffer estático para almacenar el ID leído

    if (RFID_READER.PICC_IsNewCardPresent()) {
        if (RFID_READER.PICC_ReadCardSerial()) {
           for (uint8_t i = 0; i < rfid_reader.uid.size; i++) {
                sprintf(&id[i * 2], "%02X", rfid_reader.uid.uidByte[i]); // Convertimos a hexadecimal
            }
            id[rfid_reader.uid.size * 2] = '\0'; 
            return id;
        }
    }
    return nullptr;
}


void compare_content_read_rfid_to_keys(){
    if(strcmp(reading_rfid, allowed_id) == 0){
        door_state = DOOR_OPENING;
        wrong_id = false;
        doorTimer.start(); 
    }
    if(strcmp(reading_rfid, allowed_id) != 0){
        wrong_id = true;
    }
}