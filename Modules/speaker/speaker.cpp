#include "mbed.h"

const int welcome_msg_noteDurations[] = {
  200, 250, 400
};
const int welcome_msg_melody[] = {
  659,  // E5
  698,  // F5
  784   // G5
};
const int alarm_noteDurations[] = {
    200, 250, 1000
}
const int alarm_melody[] = {
  659,  // E5
  698,  // F5
  784   // G5
};

Speaker::Speaker(PinName pwm_pin) : pwm_speaker(pwm_pin) {

}
void Speaker::play_music_welcome() {
    this -> play_melody(BUTTON_NOISE_FREQ,BUTTON_NOISE_DURATION);
}
void Speaker::play_note_button() {
    this -> play_melody(welcome_msg_melody,welcome_msg_noteDurations);
}
void Speaker::play_pwm(int* pwm_duty_list, float period) { 
    //plays a list of duty cycles in a fixed period
    
    currentNoteIndex = 0; 
    playing = true; 
}

void Speaker::play_alarm() {
    alarmStartTime = millis();
    play_melody(alarm_melody,alarm_noteDurations);
       
}
void Speaker::alarm_update(){
    float currentTime = millis(); 
    if(currentTime-alarmStartTime >= TIME_RESTART_ALARM){
        this -> play_alarm();
    }
    this -> update();
}
void Speaker::play_melody(int* melody, int* noteDurations) {
    // all duty cycles are 50%, durations in ms
    currentNoteIndex = 0; 
    playing = true; 

    currentDuration = noteDurations[currentNoteIndex];
    noteStartTime = millis(); // Record the start time

    float period = 1/melody[currentNoteIndex]
    pwm_speaker.period(period)
    pwm_speaker.write(0.5f);   
    
}

void Speaker::update() {
    if (!playing){
        return;
    } 

    float currentTime = millis();

    
    if (currentTime - noteStartTime >= currentDuration) {
        // Move to the next note
        currentNoteIndex++;

        // If we reach the end of the melody, stop playing
        if (currentNoteIndex >= sizeof(melody) / sizeof(melody[0])) {
            pwm_speaker.write(0.0f); // Stop playing
            playing = false; // Reset playing flag
            return;
        }

        // Update for the next note
        currentDuration = noteDurations[currentNoteIndex];
        noteStartTime = currentTime; // Reset the start time
        float period = 1/melody[currentNoteIndex]
        pwm_speaker.period(period)
        pwm_speaker.write(0.5f); 
    }
}

