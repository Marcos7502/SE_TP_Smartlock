#ifndef KEYPAD_H
#define KEYPAD_H



class Keyboard {
    public:
        int add(int a, int b);
        int subtract(int a, int b);
    private:
        typedef enum {
            MATRIX_KEYPAD_SCANNING,
            MATRIX_KEYPAD_DEBOUNCE,
            MATRIX_KEYPAD_KEY_HOLD_PRESSED
        } matrixKeypadState_t;


        matrixKeypadState_t matrixKeypadState;
};
#endif
