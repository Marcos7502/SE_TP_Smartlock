#include "keypad.h"

char Keypad::matrixKeypadUpdate(){
    char keyDetected = '\0';
    char keyReleased = '\0';
    static char matrixKeypadLastkeyReleased = '\0';


    switch( matrixKeypadState ) {
    case MATRIX_KEYPAD_SCANNING:
        keyDetected = _matrixKeypadScan();
        if( keyDetected != '\0' ) {
            matrixKeypadLastkeyReleased = keyDetected;
            KeypadDebouncetimer.start();
            matrixKeypadState = MATRIX_KEYPAD_DEBOUNCE;
        }
        break;
    case MATRIX_KEYPAD_DEBOUNCE:
        time_debounce = KeypadDebouncetimer.read_ms();
        if( time_debounce >=
            DEBOUNCE_BUTTON_TIME_MS ) {
            keyDetected = _matrixKeypadScan();
            if( keyDetected == matrixKeypadLastkeyReleased ) {
                matrixKeypadState = MATRIX_KEYPAD_KEY_HOLD_PRESSED;
           } else {
                matrixKeypadState = MATRIX_KEYPAD_SCANNING;
            }
        }
        break;
    case MATRIX_KEYPAD_KEY_HOLD_PRESSED:
        keyDetected = _matrixKeypadScan();
        if( keyDetected != matrixKeypadLastkeyReleased ) {
            if( keyDetected == '\0' ) {
                keyReleased = matrixKeypadLastkeyReleased;
            }
            matrixKeypadState = MATRIX_KEYPAD_SCANNING;
        }
        break;
    default:
        _matrixKeypadInit();
        break;
    }
    return keyReleased;
}

char Keypad::_matrixKeypadScan() {
  return '\0';
}
void Keypad::_matrixKeypadInit() {
  
}
void Keypad::set_debounce(int ms) {
    DEBOUNCE_BUTTON_TIME_MS = ms;
}