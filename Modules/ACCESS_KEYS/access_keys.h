#ifndef ACCESS_KEYS_H
#define ACCESS_KEYS_H
#include "mbed.h"
#include "arm_book_lib.h"

#include "string.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include "UART_comm.h"
typedef enum {
    ACCESS_GRANTED,
    ACCESS_DENIED,
    NO_ACCESS_ATTEMPT
} access_state;

access_state access_attempt_update(char* rfid_content, char* keypad_sequence_read);
void access_keys_save_id(char* rfid_content);
bool isCodePresent(char* code);
bool isRFIDPresent(char* code);
void ProcessSecurityMessage(char* message);
int my_strcmp(const char *str1, const char *str2);
#endif