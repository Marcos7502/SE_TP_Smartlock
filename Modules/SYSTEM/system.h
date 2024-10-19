#ifndef SYSTEM_H
#define SYSTEM_H
typedef enum{
    DOOR_OPENING,
    DOOR_OPEN,
    DOOR_CLOSING,
    DOOR_CLOSED
}door_state;

void system_init();

door_state system_door_closed_update();
door_state system_door_closing_update();
door_state system_door_open_update();
door_state system_door_opening_update();

void blink_leds();
#endif