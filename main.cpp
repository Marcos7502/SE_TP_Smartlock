#include "mbed.h"
#include "arm_book_lib.h"
#include "global_defines.h" 
#include "MFRC522.h"
#include <string.h>
#include <SPI.h>

char allowed_id[20] = "";  // ID permitido
char reading_rfid[20] = "";
char* rfid_content = nullptr;
int timer_door_open;
bool dooropen = false;
bool wrong_id = false;
bool open_door = false;
bool save_id = false;

DigitalIn doorblockbutton (PIN_BUTTON_DOOR_BLOCK);
DigitalOut doorblockedLED(PIN_LED_DOOR_BLOCKED);
DigitalOut dooropenLED(PIN_LED_DOOR_OPEN);


UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
MFRC522    RFID_READER   (PIN_RFID_MOSI, PIN_RFID_MISO, PIN_RFID_SCK, PIN_RFID_CS, PIN_RFID_RESET);

void uartInit();
void uartTask();
char* RFID_read(MFRC522& rfid_reader);
void compare_content_read_rfid_to_keys();

Timer doorTimer;

int main()
{   
    doorblockbutton.mode(PullDown);
    RFID_READER.PCD_Init();
    doorTimer.reset();
    open_door = false;

    while (true) {
        timer_door_open = doorTimer.read_ms();
        if( (timer_door_open!=0) && (timer_door_open < 10000)){
            if(doorblockbutton.read() == ON){
                open_door = false; 
            }
        }
        else{
            if(timer_door_open>=10000){
                
                open_door = false; 

            }
            rfid_content = RFID_read(RFID_READER); 
            if(rfid_content != nullptr){
                strcpy(reading_rfid, rfid_content);
            }
            uartTask();
            if(save_id == true && rfid_content != nullptr){
                strcpy(allowed_id, rfid_content);
                save_id = false;
                uartUsb.write("Saved ID\r\n",8);

            }
            if(rfid_content != nullptr){
                compare_content_read_rfid_to_keys();
            }
             
            if(wrong_id == true){
                open_door = false;
                wrong_id = false;
            }
            if(doorblockbutton.read() == ON){
                open_door = false; 
            }
        }
        

        if(open_door == true){
            doorblockedLED = OFF;
            dooropenLED = ON;
        }
        if(open_door == false){
            doorTimer.stop();
            doorTimer.reset();
            doorblockedLED = ON;
            dooropenLED = OFF;
        }
        
    }
}

void uartTask(){
    char receivedChar = '\0';
    if( uartUsb.readable() ){
       if(rfid_content != nullptr){
           uartUsb.write( "Read ID\r\n", 9 );
           uartUsb.write( rfid_content, strlen(rfid_content) );
           uartUsb.write( "To save Tag press 1\r\n", 23 );
       }
        
       uartUsb.read( &receivedChar, 1 );
       if(receivedChar == '1'){
            save_id = true;
            uartUsb.write("Recieved char\r\n",15);
        }
    }
    
}

// Simulación de función para leer el RFID
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
        open_door = true;
        wrong_id = false;
        doorTimer.start(); 
    }
    if(strcmp(reading_rfid, allowed_id) != 0){
        wrong_id = true;
    }
}