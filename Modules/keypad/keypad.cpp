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
void Keypad::init(){
    CodeTimeoutTimer.reset();
    CodeTimeoutTimer.stop();
    
}
void Keypad::reset(){
    for (int i = 0; i < 4; i++) {
        keypad_sequence_read[i]='\0';
    }
}
char* Keypad::get_code(){
    //Returns ['\0', ..., '\0'] if no code is read
    //Returns ['\n', ...,'\n'] if timeout occured
    //Returns code if code length is right and no timeout occured
   
    char keyReleased = _matrixKeypadUpdate();
    static int key_counter = 0;
    if(keyReleased != '\0'){
        speaker.play_note_button();
        if(key_counter == 0){
            CodeTimeoutTimer.start();
        }
        keypad_sequence_read[key_counter] = keyReleased;

        if(key_counter == 3){
            CodeTimeoutTimer.stop();
            CodeTimeoutTimer.reset();
            key_counter = 0;
            return keypad_sequence_read;

        }
        else{
            key_counter += 1;
        }

    }
    if(CodeTimeoutTimer.read_ms() > TIMEOUT_CODE){
        key_counter = 0;
        CodeTimeoutTimer.stop();
        CodeTimeoutTimer.reset();
        for (int i = 0; i < 4; i++) {
            keypad_sequence_read[i] = '\n';
        }
        return keypad_sequence_read;
    } 

    return default_incomplete_read_sequence;


}
char Keypad::_matrixKeypadUpdate(){
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