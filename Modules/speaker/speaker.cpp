#include "mbed.h"
#include "speaker.h"
#include "global_defines.h"

// Define note durations and periods for melodies
// The periods are calculated from the frecuencies of musical notes  (A5, E5, etc) (see the musical notes from a piano)
// For example, C5 = 523,25 Hz -> C5 = 0.00191 s. 
// The durations of the played musical notes are expressed in ms.
int welcome_msg_noteDurations[] = { 200, 250, 400 };//in ms
float welcome_msg_melody[] = { 0.00191, 0.00143, 0.001275 };  

int alarm_noteDurations[] = { 250, 250, 250, 250, 250, 2000 };
float alarm_melody[] = { 0.001275, 0.00143, 0.001275, 0.00143, 0.001275, 0.00143 }; 

int incorrectcodeDurations[] = { 250, 250, 250, 250, 250, 250 };
float incorrectcode_melody[] = { 0.001275, 0.00143, 0.001275, 0.00143, 0.001275, 0.00143 };  


float button_noise_period[] = { BUTTON_NOISE_PERIOD };
int button_noise_duration[] = { BUTTON_NOISE_DURATION };

Speaker::Speaker(PinName pwm_pin) : pwm_speaker(pwm_pin) {}


void Speaker::play_music_welcome() {
    this->play_melody(welcome_msg_melody, welcome_msg_noteDurations, 3);
}
void Speaker::play_incorrectcode() {
    this->play_melody(incorrectcode_melody, incorrectcodeDurations, 6);
}


void Speaker::play_note_button() {
    this->play_melody(button_noise_period, button_noise_duration , 1);
}

void Speaker::play_alarm() {
    alarmStartTime = us_ticker_read();
    play_melody(alarm_melody, alarm_noteDurations, 6);
}


void Speaker::alarm_update(){
    uint64_t currentTime = us_ticker_read(); 
    if (currentTime - alarmStartTime >= TIME_RESTART_ALARM) {
        this->play_alarm();
    }
    this->update();
}


void Speaker::play_melody(float* melody_in, int* noteDurations_in, int length) {
    melody = melody_in;
    noteDurations = noteDurations_in;
    melodyLength = length; 

    currentNoteIndex = 0;
    playing = true;
    currentnoteDuration = noteDurations[currentNoteIndex];
 
    pwm_speaker.period( melody[currentNoteIndex]);
    pwm_speaker.write(0.5f);
    Speakertimer.start();   
}

// Update function to handle melody progression
void Speaker::update() {
    if (!playing) {
        return;
    } 

    if (Speakertimer.read_ms() >= currentnoteDuration) {
        Speakertimer.reset();
        currentNoteIndex++;

        // Stop playing if we reach the end of the melody
        if (currentNoteIndex >= melodyLength) {
            
            Speakertimer.stop();
            pwm_speaker.write(0.0f); // Stop playing
            playing = false;
            return;
        }

        // Move to the next note
        currentnoteDuration = noteDurations[currentNoteIndex];
    
        pwm_speaker.period(melody[currentNoteIndex]);
        pwm_speaker.write(0.5f); 
    }
}
