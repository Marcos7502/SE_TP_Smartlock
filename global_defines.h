
// Para el RFID se usa el SPI4
#define PIN_RFID_MOSI PE_6
#define PIN_RFID_MISO PE_5
#define PIN_RFID_SCK PE_2
#define PIN_RFID_CS PE_4
#define PIN_RFID_RESET PE_3

//LEDS
#define PIN_LED_DOOR_BLOCKED D0
#define PIN_LED_DOOR_OPEN D1

//BUTTONS
#define PIN_BUTTON_DOOR_BLOCK D7

//MAGNETIC SENSORS
#define PIN_MAGNET_SENSOR_1 D8


//KEYPAD
#define KEYPAD_NUMBER_OF_ROWS       4
#define KEYPAD_NUMBER_OF_COLS       4
#define TIMEOUT_CODE                10000
#define TIMEOUT_DOOR_OPEN           10000 
#define LED_BLINK_INTERVAL          1000       




#define WRONG_ID_BLINKS 6