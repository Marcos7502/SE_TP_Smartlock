#include "MQTT.h"


MQTT::MQTT(PinName Tx, PinName Rx, int baudrate):
    esp32UART(Tx,Rx,baudrate)
{
   
    
}


MQTTMessage MQTT::receive() {
    MQTTMessage result;
    result.received = false;

    if (!this->esp32UART.readable()) {
        return result;
    }
    
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
// void MQTT::keepAlive() {
//   unsigned long currentMillis = millis();
//   if (currentMillis - previousMillis >= KeepAliveInterval) {
//       previousMillis = currentMillis; // Update the last keep-alive timestamp
//       mqttClient.publish("Smartlock/1/Alive", "alive"); // Send keep-alive message
//   }
// }