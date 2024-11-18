#ifndef KEYPAD_H
#define KEYPAD_H
#include "mbed.h"
#include "global_defines.h"


class Keypad{
    public:
        Keypad(PinName rowPins[], PinName colPins[]);
        char* get_code();
        void set_debounce(int ms);
        void init();
        void reset();
        bool button_pressed();
    private:
        DigitalOut keypadRowPins[KEYPAD_NUMBER_OF_ROWS] = {PB_3, PB_5, PC_7, PA_15};
        DigitalIn keypadColPins[KEYPAD_NUMBER_OF_COLS] = {PB_12, PB_13, PB_15, PC_6};
        typedef enum {
            MATRIX_KEYPAD_SCANNING,
            MATRIX_KEYPAD_DEBOUNCE,
            MATRIX_KEYPAD_KEY_HOLD_PRESSED
        } matrixKeypadState_t;
        
        Timer KeypadDebouncetimer;
        Timer CodeTimeoutTimer;
        matrixKeypadState_t matrixKeypadState;
        int time_debounce=0;
        int DEBOUNCE_BUTTON_TIME_MS = 40;

        char keypad_sequence_read[4];
        char default_incomplete_read_sequence[4]= {'\0', '\0', '\0' ,'\0'};
        
        char keyDetected = '\0';
        char keyReleased = '\0';

        char _matrixKeypadScan();
        void _matrixKeypadInit();
        char _matrixKeypadUpdate();
};
#endif
