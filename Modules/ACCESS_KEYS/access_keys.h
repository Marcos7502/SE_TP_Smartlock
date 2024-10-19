#ifndef ACCESS_KEYS_H
#define ACCESS_KEYS_H

typedef enum {
    ACCESS_GRANTED,
    ACCESS_DENIED,
    NO_ACCESS_ATTEMPT
} access_state;

access_state access_attempt_update(char* rfid_content, char* keypad_sequence_read);
void access_keys_save_id(char* rfid_content);
#endif