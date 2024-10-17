#ifndef KEYPAD_H
#define KEYPAD_H
#include "mbed.h"
#include "global_defines.h"


class Keypad{
    public:
        Keypad(PinName rowPins[], PinName colPins[]);
        char matrixKeypadUpdate();
        void set_debounce(int ms);
    private:
        DigitalOut keypadRowPins[KEYPAD_NUMBER_OF_ROWS] = {PB_3, PB_5, PC_7, PA_15};
        DigitalIn keypadColPins[KEYPAD_NUMBER_OF_COLS] = {PB_12, PB_13, PB_15, PC_6};
        typedef enum {
            MATRIX_KEYPAD_SCANNING,
            MATRIX_KEYPAD_DEBOUNCE,
            MATRIX_KEYPAD_KEY_HOLD_PRESSED
        } matrixKeypadState_t;
        
        Timer KeypadDebouncetimer;
        matrixKeypadState_t matrixKeypadState;
        int time_debounce=0;
        int DEBOUNCE_BUTTON_TIME_MS = 40;
        char _matrixKeypadScan();
        void _matrixKeypadInit();
};
#endif
