#ifndef KEYPAD_H
#define KEYPAD_H
#include "mbed.h"


class Keypad {
    public:
        char matrixKeypadUpdate();
        void set_debounce(int ms);
    private:
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
