#include "keypad.h"
#include "mbed.h"
#include "arm_book_lib.h"

Keypad::Keypad( PinName* rowPinslist, PinName* colPinslist){
    matrixKeypadState = MATRIX_KEYPAD_SCANNING;
    for (int i = 0; i < KEYPAD_NUMBER_OF_ROWS; i++) {
        keypadRowPins[i] =  rowPinslist[i];
    }

    for (int i = 0; i < KEYPAD_NUMBER_OF_COLS; i++) {
        keypadColPins[i] = colPinslist[i];
        (keypadColPins[i]).mode(PullUp);
    }
}

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
    int r = 0;
    int c = 0;
    int i = 0;
    char matrixKeypadIndexToCharArray[] = {
        '1', '2', '3', 'A',
        '4', '5', '6', 'B',
        '7', '8', '9', 'C',
        '*', '0', '#', 'D',
    };
    
    for( r=0; r<KEYPAD_NUMBER_OF_ROWS; r++ ) {
        for( i=0; i<KEYPAD_NUMBER_OF_ROWS; i++ ) {
            keypadRowPins[i] = ON;
        }
        keypadRowPins[r] = OFF;
        for( c=0; c<KEYPAD_NUMBER_OF_COLS; c++ ) {
            if( keypadColPins[c] == OFF ) {
                return matrixKeypadIndexToCharArray[r*KEYPAD_NUMBER_OF_ROWS + c];
            }
        }
    }
    return '\0';
}
void Keypad::_matrixKeypadInit() {
    matrixKeypadState = MATRIX_KEYPAD_SCANNING;
    int pinIndex = 0;
    for( pinIndex=0; pinIndex<KEYPAD_NUMBER_OF_COLS; pinIndex++ ) {
        (keypadColPins[pinIndex]).mode(PullUp);
    }
}
void Keypad::set_debounce(int ms) {
    DEBOUNCE_BUTTON_TIME_MS = ms;
}