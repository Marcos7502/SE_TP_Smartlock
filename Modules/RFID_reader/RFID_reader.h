#ifndef RFID_READER
#define RFID_READER
#include "mbed.h"
#include "global_defines.h"
#include "MFRC522.h"

char* RFID_read();
void RFID_reader_init();

#endif