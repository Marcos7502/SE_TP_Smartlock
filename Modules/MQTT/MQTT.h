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

        DigitalOut LedMqtt;


        // Crea el objeto
        MQTT(PinName Tx, PinName Rx, int baudrate,PinName pin_led_mqtt);

        // Keep alive
        void keepAlive();

        // Keep alive
        void SendStatus(char* status_code);

        // Se suscribe a un tópico
        void subscribe(const char * topic);

        // Se desuscribe a un tópico
        void unsubscribe(const char * topic);

        // Envía un mensaje a un tópico
        void publish(const char * topic, const char * message);

        //
        MQTTMessage receive();

        //Logger
        void SendLogAccessMessage(char* rfid_content, char* keypad_code);
        void SendLogDoorLeftOpenMessage(bool door_left_open);
        void SendLogWrongIDMessage();

        //Logger
        void ShowRFID(char* buffer);
        




        // void confirmSubscription(const char* topic);
        // void confirmUnsubscription(const char* topic);


    private:
        unsigned int previousMillis = 0;

        const char * subscribe_str = "subscribe";
        const char * unsubscribe_str = "unsubscribe";


        // std::vector<std::string> subscribedTopics;
        // std::vector<std::string> pendingSubscriptions;
        // std::vector<std::string> pendingUnsubscriptions;
        // std::vector<PendingMessage_t> pendingMessages;

        bool reset_subscriptions = false;



        void int_MQTT_status_callback_on();
        void int_MQTT_status_callback_off();
        void int_MQTT_mensaje_callback();

        void delay_callback();

        void write(const char * topic, const char * message);

        
};

//=====[Declarations (prototypes) of public functions]=========================

//=====[#include guards - end]=================================================

#endif // _MQTT_H_