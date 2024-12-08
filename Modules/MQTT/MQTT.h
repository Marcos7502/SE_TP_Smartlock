#ifndef _MQTT_H_
#define _MQTT_H_

#include "mbed.h"
#include "arm_book_lib.h"
#include "global_defines.h"
#include "string.h"
#include <iostream>



struct MQTTMessage {
    char* topic;
    char* message;
    bool received;
};

class MQTT{
    public:
        // Conexión con el módulo esp32 que maneja MQTT
        BufferedSerial esp32UART;

        // Led que muestra la conexion
        DigitalOut LedMqtt;


        // Crea el objeto
        MQTT(PinName Tx, PinName Rx, int baudrate,PinName pin_led_mqtt);

        // Keep alive
        void keepAlive();

        // Status
        void SendStatus(char* status_code);


        // Envía un mensaje a un tópico
        void publish(const char * topic, const char * message);

        //
        MQTTMessage receive();

        //Logger
        void SendLogAccessMessage(char* rfid_content, char* keypad_code);
        void SendLogDoorLeftOpenMessage(bool door_left_open);
        void SendLogWrongIDMessage();

        //RFID
        void ShowRFID(char* buffer);
        
        void LedUpdate();


    private:
        bool blink_mqtt_led = false;
        unsigned int previousMillis = 0;
        unsigned int LedOffTimeMillis = 0;

        void write(const char * topic, const char * message);

        
};

//=====[Declarations (prototypes) of public functions]=========================

//=====[#include guards - end]=================================================

#endif // _MQTT_H_