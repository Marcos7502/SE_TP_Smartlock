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
    LedMqtt = ON;
    delay(100);
    LedMqtt = OFF;

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
      previousMillis = currentMillis; // Update the last keep-alive timestamp
      this-> write("Smartlock/1/Alive", "alive"); // Send keep-alive message
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

    