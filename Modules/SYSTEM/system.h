#ifndef SYSTEM_H
#define SYSTEM_H
typedef enum{
    DOOR_OPENING,
    DOOR_OPEN,
    DOOR_CLOSING,
    DOOR_CLOSED,
    NONE
}door_state;

typedef enum{
    WAITING,
    IDLE
}delay_motor;

void force_door_close();
void system_init();
void system_update();
void blink_leds();
void process_mqtt();
void ringbell();
void stopringbell();
void update_delay_motor();

door_state system_door_closed_update();
door_state system_door_closing_update();
door_state system_door_open_update();
door_state system_door_opening_update();


#endif