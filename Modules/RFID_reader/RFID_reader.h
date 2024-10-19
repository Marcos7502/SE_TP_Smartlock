#ifndef RFID_READER
#define RFID_READER
#include "mbed.h"
#include "global_defines.h"
#include "MFRC522.h"
/* MFRC522.h - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT.
Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
Created by Miguel Balboa (circuitito.com), Jan, 2012.
Rewritten by Soren Thing Andersen (access.thing.dk), fall of 2013 (Translation to English, refactored, comments, anti collision, cascade levels.)
Ported to mbed by Martin Olejar, Dec, 2013
Link: https://os.mbed.com/teams/Project5_Software/code/RFID-RC522/docs/tip/MFRC522_8h_source.html
*/


char* RFID_read();
void RFID_reader_init();

#endif