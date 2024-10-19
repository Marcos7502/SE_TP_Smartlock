#ifndef UART_COMM
#define UART_COMM
#include "mbed.h"
#include "global_defines.h"

void UARTShowRFID(char* rfid_content);
void UART_send_access_message(char* rfid_content, char* keypad_code);
void UART_send_door_left_open_message(bool doorleftopen);
void UART_send_wrong_id_message();
bool UART_get_save_id_input();
void UART_notify_ID_was_saved(char* rfid_content);

#endif