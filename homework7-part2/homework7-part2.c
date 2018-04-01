#include <stdlib.h>
#include "swtimer.h"
#include "hwtimer.h"
#include "sound.h"
#include "button.h"

// This expresses the unit-duration (1/16th of a full note) in ms
#define DURATION 100

int main(void) {

    // Device Initialization
    InitTimer();
    InitSound();
    InitButtonS1();
    InitButtonS2();

    while (1) {

        // The first song is tied to the first button
        if (ButtonS1Pushed()) {
            PlaySound(note_g4,  2*DURATION);   // G4 // 2
            PlaySound(note_c5,  2*DURATION);   // C5 // 2
            PlaySound(note_e5,    DURATION);   // E5 // 1
            PlaySound(note_c5,    DURATION);   // C5 // 1
            PlaySound(note_g4,  2*DURATION);   // G4 // 2
            PlaySound(note_e5,  2*DURATION);   // E5 // 2
            PlaySound(note_c5,  2*DURATION);   // C5 // 2
            PlaySound(note_e5,    DURATION);   // E5 // 1
            PlaySound(note_c5,    DURATION);   // C5 // 1
            PlaySound(note_g4,  2*DURATION);   // G4 // 2
            PlaySound(note_e5,  2*DURATION);   // E5 // 2
            PlaySound(note_c5,  2*DURATION);   // C5 // 2
            PlaySound(note_e5,    DURATION);   // E5 // 1
            PlaySound(note_c5,    DURATION);   // C5 // 1
            PlaySound(note_g4,  2*DURATION);   // G4 // 2
            PlaySound(note_c5,  2*DURATION);   // C5 // 2
            PlaySound(note_e5,  4*DURATION);   // E5 // 4
            PlaySound(note_c5,  4*DURATION);   // C5 // 4
            PlaySound(note_g4,  3*DURATION);   // G4 // 3
            PlaySound(note_a4,    DURATION);   // A4 // 1
            PlaySound(note_b4,  2*DURATION);   // B4 // 2
            PlaySound(note_c5,  2*DURATION);   // C5 // 2
            PlaySound(note_d5,  2*DURATION);   // D5 // 2
            PlaySound(note_e5,  2*DURATION);   // E5 // 2
            PlaySound(note_f5,  2*DURATION);   // F5 // 2
            PlaySound(note_fs5, 2*DURATION);   // F#5 // 2
            PlaySound(note_g5, 16*DURATION);   // G5 // 16
        }

        // The second song is tied to the second button
        if (ButtonS2Pushed()) {
            PlaySound(note_g4,  2*DURATION);   // G4 // 2
            PlaySound(note_a4,  2*DURATION);   // A4 // 2
            PlaySound(note_b4,  2*DURATION);   // B4 // 2
            PlaySound(note_c5,    DURATION);   // C5 // 1
            PlaySound(note_silent,DURATION);   // Silence // 1
            PlaySound(note_c5,  6*DURATION);   // C5 // 6
            PlaySound(note_e5,    DURATION);   // E5 // 1
            PlaySound(note_silent,DURATION);   // Silence // 1
            PlaySound(note_e5,  6*DURATION);   // E5 // 6
            PlaySound(note_f5,    DURATION);   // F5 // 1
            PlaySound(note_silent,DURATION);   // Silence // 1
            PlaySound(note_f5,  6*DURATION);   // F5 // 6
            PlaySound(note_fs5, 8*DURATION);   // F#5 // 8
            PlaySound(note_g5,  2*DURATION);   // G5 // 2
            PlaySound(note_g4,  2*DURATION);   // G4 // 2
            PlaySound(note_a4,  2*DURATION);   // A4 // 2
            PlaySound(note_c5,  2*DURATION);   // C5 // 2
            PlaySound(note_d5,  2*DURATION);   // D5 // 2
            PlaySound(note_c6, 10*DURATION);   // C6 // 10
            PlaySound(note_silent,2*DURATION); // Silence // 2
            PlaySound(note_c6,    DURATION);   // C6 // 1
        }
    }
}
