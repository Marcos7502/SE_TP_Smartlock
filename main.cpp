#include "mbed.h"
#include "arm_book_lib.h"
#include "global_defines.h"
#include "system.h"

door_state main_door_state;
InterruptIn  doorblockbutton(PIN_BUTTON_DOOR_BLOCK);
void force_door_close();

int main(){
    main_door_state = DOOR_CLOSED; 
    doorblockbutton.mode(PullDown);
    doorblockbutton.rise(&force_door_close);
    system_init();
    while (true) {
        switch(main_door_state){
            case DOOR_CLOSED:
                main_door_state = system_door_closed_update();           
                break;
            
            case DOOR_OPENING:
                main_door_state = system_door_opening_update();
                break;
            
            case DOOR_OPEN:
                main_door_state = system_door_open_update();
                break;

            case DOOR_CLOSING:
                main_door_state = system_door_closing_update();         
                break;
        }
   
    }
}

void force_door_close(){
    main_door_state = DOOR_CLOSING; 
}
