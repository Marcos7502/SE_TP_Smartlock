#include "access_keys.h"
#include "mbed.h"
#include "arm_book_lib.h"
#include "UART_comm.h"

char keypad_code[4] = {'1' ,'2' ,'3' ,'4'}; 
char allowed_id[20] = "";  // ID permitido

access_state access_attempt_update(char* rfid_content, char* keypad_sequence_read){
    if(rfid_content!= nullptr){
        if(strcmp(rfid_content, allowed_id) == 0){
            return ACCESS_GRANTED;
        }else{
            return ACCESS_DENIED;
        }
    }
    if(keypad_sequence_read[0] != '\0'){
        for (int i = 0; i < 4; i++) {
            if (keypad_code[i] != keypad_sequence_read[i]) {
                return ACCESS_DENIED;
            }
        }
        return ACCESS_GRANTED;
    }
    return NO_ACCESS_ATTEMPT;
    
}
void access_keys_save_id(char* rfid_content){
    if(rfid_content!= nullptr){
        strncpy(allowed_id, rfid_content,sizeof(allowed_id));
    }
    UART_notify_ID_was_saved();
}

