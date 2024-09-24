#include "keypad.h"

char Keyboard::matrixKeypadUpdate(){
    char keyDetected = '\0';
    char keyReleased = '\0';
    switch( matrixKeypadState ) {
    case MATRIX_KEYPAD_SCANNING:
        keyDetected = matrixKeypadScan();
        if( keyDetected != '\0' ) {
            matrixKeypadLastkeyReleased = keyDetected;
            accumulatedDebounceMatrixKeypadTime = 0;
            matrixKeypadState = MATRIX_KEYPAD_DEBOUNCE;
        }
        break;
    case MATRIX_KEYPAD_DEBOUNCE:
        if( accumulatedDebounceMatrixKeypadTime >=
            DEBOUNCE_BUTTON_TIME_MS ) {
            keyDetected = matrixKeypadScan();
            if( keyDetected == matrixKeypadLastkeyReleased ) {
                matrixKeypadState = MATRIX_KEYPAD_KEY_HOLD_PRESSED;
           } else {
                matrixKeypadState = MATRIX_KEYPAD_SCANNING;
            }
        }
        accumulatedDebounceMatrixKeypadTime =
            accumulatedDebounceMatrixKeypadTime + TIME_INCREMENT_MS;

}

int Keyboard::subtract(int a, int b) {
    return a - b;
}

char matrixKeypadUpdate()
 {
    
