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
char UsbBuffer[32];

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


UnbufferedSerial UARTUsb(USBTX, USBRX, 115200);
MFRC522    RFID_READER   (PIN_RFID_MOSI, PIN_RFID_MISO, PIN_RFID_SCK, PIN_RFID_CS, PIN_RFID_RESET);


void system_init();
char* RFID_read(MFRC522& rfid_reader);
void compare_content_read_rfid_to_keys();
void blink_leds();

void UARTShowRFID();
void UART_send_access_message();
void UART_send_door_left_open_message();

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
                

                rfid_content = RFID_read(RFID_READER);
                if(rfid_content != nullptr){
                    strncpy(reading_rfid, rfid_content,sizeof(reading_rfid) );
                }
                UARTShowRFID();
                if(save_id == true && rfid_content != nullptr){
                    strncpy(allowed_id, rfid_content,sizeof(allowed_id));
                    save_id = false;
                    UARTUsb.write("Saved ID\r\n",8);
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

                    time_t seconds = time(NULL);
                    UARTUsb.write("Door 1 wrong ID introduced at ",30);
                    strftime(UsbBuffer, 24, "%c", localtime(&seconds));
                    UARTUsb.write(UsbBuffer,24);
                    UARTUsb.write("\r\n",2);

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
                UART_send_access_message();
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
                        UART_send_door_left_open_message();
                        
                    }
                    if(doorleftopen == true){
                        blink_leds();
                    }                                        
                        
                }

                if(magnetsensor == ON){
                    blinks_counter = 0;
                    if(doorleftopen == true){
                        doorleftopen = false;
                        UART_send_door_left_open_message();
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
    

    RFID_READER.PCD_Init();


    door_state=DOOR_CLOSED;

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

// Module: UART communications: Show RFID  -------------------------
void UARTShowRFID(){
    char receivedChar = '\0';
    
    if(rfid_content != nullptr){
        UARTUsb.write( "Read ID: ", 9 );
        UARTUsb.write( rfid_content, strlen(rfid_content) );
        UARTUsb.write( "\r\n ", 2 );
        UARTUsb.write( "To save Tag press 1\r\n", 23 );
    }
    if( UARTUsb.readable() ){
       UARTUsb.read( &receivedChar, 1 );
       if(receivedChar == '1'){
            save_id = true;
            UARTUsb.write("Received save\r\n",15);
        }
    }
    
}
// Module: UART Communications: Message Door Open ---------
void UART_send_access_message(){
    time_t seconds = time(NULL);
    strftime(UsbBuffer, 24, "%c", localtime(&seconds));
    if(rfid_content !=nullptr){
        UARTUsb.write( "Door 1 accessed on ", 19);
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write(" with RFID ID: ",15);
        UARTUsb.write(rfid_content, strlen(rfid_content));
        UARTUsb.write( "\r\n ", 2 );
    }else{
        UARTUsb.write( "Door 1 accessed on ", 19);
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write(" with Keypad Code: ",19);
        UARTUsb.write(keypad_code, 4);

        UARTUsb.write( "\r\n ", 2 );
    }
    
}

// Modue: UART Communications: Message Access --------
void UART_send_door_left_open_message(){
    time_t seconds = time(NULL);
    strftime(UsbBuffer, 24, "%c", localtime(&seconds));
    if(doorleftopen == true){
        
        
        UARTUsb.write("Door 1 left open on ", 20);
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write("\r\n ", 2);
    }
    if(doorleftopen == false){
        UARTUsb.write("Door 1 left open was closed on ", 31);
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write("\r\n ", 2);
    }
    
}