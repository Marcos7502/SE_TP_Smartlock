#include "mbed.h"
#include "UART_comm.h"
#include "MFRC522.h"
#include <cstring>

static bool rfid_allow_read = true;

MFRC522    RFID_READER   (PIN_RFID_MOSI, PIN_RFID_MISO, PIN_RFID_SCK, PIN_RFID_CS, PIN_RFID_RESET);
Timer PausereadingTimer;

// Module: RFID reader  -------------------------
char* RFID_read(){
   static char id[20] = ""; // Buffer estático para almacenar el ID leído
    if(rfid_allow_read==true){
        if (RFID_READER.PICC_IsNewCardPresent()) {
            if (RFID_READER.PICC_ReadCardSerial()) {
            for (uint8_t i = 0; i < RFID_READER.uid.size; i++) {
                    sprintf(&id[i * 2], "%02X", RFID_READER.uid.uidByte[i]); // Convertimos a hexadecimal
                }
                id[RFID_READER.uid.size * 2] = '\0'; 
                PausereadingTimer.start();
                if(rfid_allow_read==true){
                    rfid_allow_read=false;
                }
                return id;
            }
        }
    }

    if(PausereadingTimer.read_ms() >2000){
        PausereadingTimer.reset();
        rfid_allow_read=true;
    }
    if(PausereadingTimer.read_ms() >10000){
        PausereadingTimer.stop();
        PausereadingTimer.reset();
        rfid_allow_read=true;
    }
    return nullptr;
}
void RFID_reader_init(){
    RFID_READER.PCD_Init();
}