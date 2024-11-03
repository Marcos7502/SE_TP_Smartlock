#include "mbed.h"
#include "speaker.h"
#include "global_defines.h"

// Define note durations and frequencies for melodies
int welcome_msg_noteDurations[] = { 200, 250, 400 };
int welcome_msg_melody[] = { 659, 698, 784 };  // E5, F5, G5

int alarm_noteDurations[] = { 200, 250, 1000 };
int alarm_melody[] = { 659, 698, 784 };  // E5, F5, G5

int button_noise_freq[] = { BUTTON_NOISE_FREQ };
int button_noise_duration[] = { BUTTON_NOISE_DURATION };

Speaker::Speaker(PinName pwm_pin) : pwm_speaker(pwm_pin) {}

// Play a short welcome sound
void Speaker::play_music_welcome() {
    this->play_melody(button_noise_freq, button_noise_duration, 1);
}

// Play a predefined melody for button press
void Speaker::play_note_button() {
    this->play_melody(welcome_msg_melody, welcome_msg_noteDurations, 3);
}

// Play an alarm melody
void Speaker::play_alarm() {
    alarmStartTime = us_ticker_read();
    play_melody(alarm_melody, alarm_noteDurations, 3);
}

// Update the alarm playback
void Speaker::alarm_update(){
    uint64_t currentTime = us_ticker_read(); 
    if (currentTime - alarmStartTime >= TIME_RESTART_ALARM) {
        this->play_alarm();
    }
    this->update();
}

// Main function to play a melody
void Speaker::play_melody(int* melody_in, int* noteDurations_in, int length) {
    melody = melody_in;
    noteDurations = noteDurations_in;
    melodyLength = length; // Store the length of the melody

    currentNoteIndex = 0;
    playing = true;
    currentnoteDuration = noteDurations[currentNoteIndex];
    noteStartTime = us_ticker_read();

    float period = 1.0 / melody[currentNoteIndex];
    pwm_speaker.period(period);
    pwm_speaker.write(0.5f);   
}

// Update function to handle melody progression
void Speaker::update() {
    if (!playing) {
        return;
    } 

    uint64_t currentTime = us_ticker_read();

    if (currentTime - noteStartTime >= currentnoteDuration) {
        currentNoteIndex++;

        // Stop playing if we reach the end of the melody
        if (currentNoteIndex >= melodyLength) {
            pwm_speaker.write(0.0f); // Stop playing
            playing = false;
            return;
        }

        // Move to the next note
        currentnoteDuration = noteDurations[currentNoteIndex];
        noteStartTime = currentTime;

        float period = 1.0 / melody[currentNoteIndex];
        pwm_speaker.period(period);
        pwm_speaker.write(0.5f); 
    }
}
