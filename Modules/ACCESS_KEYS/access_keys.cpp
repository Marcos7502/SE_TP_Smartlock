#include "access_keys.h"



// Define a struct to hold the information
struct AccessKey{
    int id;
    std::string name;
    std::string code;
    std::string rfid;
};
std::vector<AccessKey> StoredKeys;
char keypad_code[4] = {'1' ,'2' ,'3' ,'4'}; 
char allowed_id[20] = "";  // ID permitido



int my_strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        // Compare the characters at the current position
        if (*str1 != *str2) {
            return (unsigned char)*str1 - (unsigned char)*str2; // Return the difference
        }
        str1++;
        str2++;
    }

    // If both strings are of equal length and no difference found, return the difference of '\0' characters
    return (unsigned char)*str1 - (unsigned char)*str2;
}
access_state access_attempt_update(char* rfid_content_read, char* keypad_sequence_read){
    if(rfid_content_read!= nullptr){
        if(isRFIDPresent(rfid_content_read)){
            return ACCESS_GRANTED;
        }else{
            return ACCESS_DENIED;
        }
    }
    if(keypad_sequence_read[0] != '\0'){
        if(isCodePresent(keypad_sequence_read)){
            return ACCESS_GRANTED;
        }
        else{
            return ACCESS_DENIED;
        }
    }
    return NO_ACCESS_ATTEMPT;
    
}
void access_keys_save_id(char* last_rfid_content){
   
    strncpy(allowed_id,last_rfid_content,sizeof(allowed_id));
    UART_notify_ID_was_saved(last_rfid_content);
    
    
}



// Function to parse the message and add the key to the list
void ProcessSecurityMessage(char* message) {
    std::string msg(message);

    std::istringstream ss(message);
    std::string token;

   
    std::string operation, id_str, name, code_str, rfid;
    
    // Read parts of the message separated by '_'
    if (std::getline(ss, operation, '_') &&
        std::getline(ss, id_str, '_') &&
        std::getline(ss, name, '_') &&
        std::getline(ss, code_str, '_') &&
        std::getline(ss, rfid)) {
            if (rfid.empty()) {
                rfid = "-1";
            }
            // Convert id and code to integers
            int read_id = std::stoi(id_str);
            const char* operation_str = operation.c_str();
            if(my_strcmp(operation_str, "add") == 0){
                

                // Create a new record
                AccessKey key{read_id, name, code_str, rfid};
                
                // Add the record to the list
                StoredKeys.push_back(key);
            }
            else if(my_strcmp(operation_str, "delete") == 0){
                // Find the element by id and erase it
                auto it = std::find_if(StoredKeys.begin(), StoredKeys.end(), [&](const AccessKey& key) {
                    return key.id == read_id;
                });

                if (it != StoredKeys.end()) {
                    // If found, erase the element
                    StoredKeys.erase(it);
                }

            }
        }
        
}

 
bool isCodePresent(char* code) {
    
    for (const auto& key : StoredKeys) {
        const char* keycode = key.code.c_str();
        if (my_strcmp( keycode, code) == 0) {
            return true;  // Return true if the code matches
        }
    }
    return false;  // Return false if no code matches
}
bool isRFIDPresent(char* rfid) {
    for (const auto& key : StoredKeys) {
        const char* keyrfid = key.rfid.c_str();
        if (my_strcmp(keyrfid , rfid) == 0) {
            return true;  // Return true if the code matches
        }
    }
    return false;  // Return false if no code matches
}

