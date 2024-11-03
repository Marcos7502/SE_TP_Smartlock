#ifndef SPEAKER_H
#define SPEAKER_H

#define BUTTON_NOISE_FREQ 440
#define BUTTON_NOISE_DURATION 200


class Speaker {
    public:
        Speaker(PinName pwm_pin);
        void play_music_welcome();
        void play_note_button();
        void play_alarm();
        void play_pwm(int* pwm_duty_list, float period);
        void play_melody(int* melody, int* noteDurations, int melody_length);
        void alarm_update();
        void update(); 
    private:
        int* melody;
        int* noteDurations;
        int melodyLength;
        int currentNoteIndex = 0; 
        float noteStartTime = 0;
        float currentnoteDuration = 0; 
        float alarmStartTime = 0;
        bool playing = false;
        PwmOut pwm_speaker;  // PWM output object
};
#endif