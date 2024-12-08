#include "mbed.h"
#include "arm_book_lib.h"
#include "global_defines.h"
#include "system.h"



int main(){
    
    system_init();
    while (true) {
        system_update();
   
    }
}

