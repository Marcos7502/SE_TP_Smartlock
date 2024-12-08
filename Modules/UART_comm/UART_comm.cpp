#include "mbed.h"
#include "UART_comm.h"
#include <cstring>

UnbufferedSerial UARTUsb(USBTX, USBRX, 115200);
char UsbBuffer[32];
char receivedChar = '\0';

// Module: UART communications: Show RFID  -------------------------
void UARTShowRFID(char* rfid_content_send){
    
    if(rfid_content_send != nullptr){
        UARTUsb.write( "Read ID: ", 9 );
        UARTUsb.write( rfid_content_send, strlen(rfid_content_send) );
        UARTUsb.write( "\r\n ", 2 );
        UARTUsb.write( "To save Tag press 1\r\n", 21 );
    }
    
}
// Module: UART Communications: Message Door Open ---------
void UART_send_access_message(char* rfid_content, char* keypad_code){
    time_t seconds = time(NULL);
    strftime(UsbBuffer, 24, "%c", localtime(&seconds));
    if(rfid_content !=nullptr){
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write( " : Door 1 accessed with RFID ID: ", 33);
        UARTUsb.write(rfid_content, strlen(rfid_content));
        UARTUsb.write( "\r\n ", 2 );
    }else{
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write( " : Door 1 accessed with Keypad Code: ", 37);
        UARTUsb.write(keypad_code, 4);

        UARTUsb.write( "\r\n ", 2 );
    }
    
}

// Modue: UART Communications: Message Door Left Open --------
void UART_send_door_left_open_message(bool doorleftopen){
    time_t seconds = time(NULL);
    strftime(UsbBuffer, 24, "%c", localtime(&seconds));
    if(doorleftopen == true){
        
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write(" : Door 1 left open ", 20);
        UARTUsb.write("\r\n ", 2);
    }
    if(doorleftopen == false){
        UARTUsb.write(UsbBuffer, 24);
        UARTUsb.write(" : Door 1 left open was closed ", 31);
        
        UARTUsb.write("\r\n ", 2);
    }
    
}

void UART_send_wrong_id_message(){
    
    time_t seconds = time(NULL);
    strftime(UsbBuffer, 24, "%c", localtime(&seconds));
    UARTUsb.write(UsbBuffer,24);
    UARTUsb.write(" : Door 1 wrong ID introduced ",30);
    UARTUsb.write("\r\n",2);

}

bool UART_get_save_id_input(){
    if( UARTUsb.readable() ){
        UARTUsb.read( &receivedChar, 1 );
        if(receivedChar == '1'){
            UARTUsb.write("Received save\r\n",15);
            return true;
        }
    }
    return false;
}
void UART_notify_ID_was_saved(char* rfid_content){
    UARTUsb.write("Saved ID\r\n",10);
    UARTUsb.write(rfid_content,sizeof(rfid_content));
}