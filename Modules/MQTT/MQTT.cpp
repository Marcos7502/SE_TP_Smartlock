#include "MQTT.h"


MQTT::MQTT(PinName Tx, PinName Rx, int baudrate,PinName pin_led_mqtt):
    esp32UART(Tx,Rx,baudrate),
    LedMqtt(pin_led_mqtt)
{
    LedMqtt = OFF;
    
}


MQTTMessage MQTT::receive() {
    MQTTMessage result;
    result.received = false;

    if (!this->esp32UART.readable()) {
        return result;
    }
    blink_mqtt_led = true;

    char buffer[256];
    int index = 0;
    char ch = '\0';

    while (ch != '\n' && index < sizeof(buffer) - 1) {
        if (this->esp32UART.readable()) {
            this->esp32UART.read(&ch, 1);
            if (ch != '\n') {
                buffer[index++] = ch;
            }
        }
    }
    buffer[index] = '\0';

    char* separator = strchr(buffer, ':');
    if (separator != NULL) {
        *separator = '\0';
        result.topic = buffer;
        result.message = separator + 1;
        result.received = true;
    }

    return result;
}
void MQTT::keepAlive() {
    unsigned int currentMillis = Kernel::get_ms_count();
    if (currentMillis - previousMillis >= KEEP_ALIVE_INTERVAL) {
        previousMillis = currentMillis; 
        this-> write("Smartlock/1/Alive", "alive"); 
        blink_mqtt_led = true;
    }
}

void MQTT::write(const char* topic, const char* message){
    this->esp32UART.write(topic, strlen(topic));
    this->esp32UART.write(":", 1);
    this->esp32UART.write(message, strlen(message));
    this->esp32UART.write("\n", 1);

}
void MQTT::SendStatus(char* status_code){
 
    this -> write("Smartlock/1/Status",status_code);
}

void MQTT::SendLogAccessMessage(char* rfid_content, char* keypad_code){
    time_t seconds = time(NULL);
    char Buffer[64]; 
    strftime(Buffer, sizeof(Buffer), "%c", localtime(&seconds));

    char FinalMessage[150];

    if (rfid_content != nullptr) {
        sprintf(FinalMessage, "%s : Door 1 accessed with RFID ID: %s", Buffer, rfid_content);
    } else {
        sprintf(FinalMessage, "%s : Door 1 accessed with Keypad Code: %.4s", Buffer, keypad_code);
    }
    this -> write("Smartlock/1/Logger",FinalMessage);
}

void MQTT::SendLogDoorLeftOpenMessage(bool door_left_open){
    time_t seconds = time(NULL);
    char Buffer[64]; 
    strftime(Buffer, sizeof(Buffer), "%c", localtime(&seconds)); 

    char FinalMessage[100]; 

    if (door_left_open == true) {
        sprintf(FinalMessage, "%s : Door 1 left open", Buffer);
    } else {
        sprintf(FinalMessage, "%s : Door 1 left open was closed", Buffer);
    }

    this -> write("Smartlock/1/Logger",FinalMessage);
}

void MQTT::SendLogWrongIDMessage(){
    time_t seconds = time(NULL);
    char Buffer[64]; 
    strftime(Buffer, sizeof(Buffer), "%c", localtime(&seconds)); 
    char FinalMessage[100]; 
    sprintf(FinalMessage, "%s : Door 1 wrong ID introduced", Buffer); 

    this -> write("Smartlock/1/Logger",FinalMessage);
}



void MQTT::ShowRFID(char* rfid_content_send){
    if(rfid_content_send != nullptr){
        char FinalMessage[100]; 
        sprintf(FinalMessage, "NewRFID_%s", rfid_content_send); 

        this -> write("Smartlock/1/Security",FinalMessage);
    }
}
    

void MQTT::LedUpdate(){
    unsigned int currentMillis = Kernel::get_ms_count();
    if(blink_mqtt_led == true){
        LedMqtt = ON;
        blink_mqtt_led = false;
        LedOffTimeMillis = currentMillis + PIN_MQTT_LED_BLINK_TIME;
    }
    if(LedOffTimeMillis <= currentMillis){
        LedMqtt = OFF;
    }
    
}
   