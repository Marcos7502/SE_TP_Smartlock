
//Codigo basado en la implementacion de MQTT hecha por Augusto Villacampa
//https://github.com/avillacampafiuba/Proyecto_Tranquera_SE/blob/master/Codigo_ESP32.ino

#include <PubSubClient.h>
#include <WiFi.h>

WiFiClient esp32Client;
PubSubClient mqttClient(esp32Client);

const char* ssid     = "";
const char* password = "";

char *server = "192.168.0.124";
int port = 1883;

unsigned long previousMillis = 0; // Stores the last time a keep-alive was sent
const unsigned long KeepAliveInterval = 5000; // 5 seconds interval


#define RXD2 16
#define TXD2 17



void wifiInit() {

    Serial.print("Conectándose a ");
    Serial.print(ssid);
    Serial.print("\n");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);  
    }
    Serial.print("\n");
    Serial.print("Conectado a WiFi");
    Serial.print("\n");
    Serial.print("Dirección IP: ");
    Serial.print(WiFi.localIP());
    Serial.print("\n");
}

void callback(char* topic, byte* payload, unsigned int length) {
    char payload_string[length + 1];
    memcpy(payload_string, payload, length);
    payload_string[length] = '\0';
 

    Serial.print("Mensaje recibido [");
    Serial.print(topic);
    Serial.print("]: ");
    Serial.print(payload_string);
    Serial.print("\n");

    // Reenviar el mensaje por UART
    Serial2.print(topic);
    Serial2.print(":");
    Serial2.print(payload_string);
    Serial2.print("\n");

  
}

void reconnect() {
    while (!mqttClient.connected()) {
        Serial.print("Intentando conectarse MQTT...");
        Serial.print("\n");

        if (mqttClient.connect("ESP32")) {
            Serial.print("Conectado");
            Serial.print("\n");
      
            mqttClient.subscribe("Smartlock/1/Control");
            mqttClient.subscribe("Smartlock/1/Security");
            mqttClient.subscribe("Smartlock/1/Alive");
        } else {
            Serial.print("Fallo, rc=");
            Serial.print(mqttClient.state());
            Serial.print(" intentando de nuevo en 5 segundos");
            Serial.print("\n");
            delay(5000);
        }
    }
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // Configuración UART2 a 115200 baudios
  

  wifiInit();
  mqttClient.setServer(server, port);
  mqttClient.setCallback(callback);
 
}


void loop() {
    if (!mqttClient.connected()) {
        reconnect();
    }
   
    mqttClient.loop();
        

    if (Serial2.available()) {
        String uartMessage = Serial2.readStringUntil('\n'); // Leer mensaje UART
        int separatorIndex = uartMessage.indexOf(':');
        
        if (separatorIndex != -1) {
          String command = uartMessage.substring(0, separatorIndex);
          String argument = uartMessage.substring(separatorIndex + 1);

          // Publicar mensaje en MQTT
          mqttClient.publish(command.c_str(), argument.c_str());
          Serial.print("Mensaje enviado: ");
          Serial.print("\n");
          Serial.print("Tópico: ");
          Serial.print(command);
          Serial.print(", Mensaje: ");
          Serial.print(argument);
          Serial.print("\n");
          
        }
    }
}


