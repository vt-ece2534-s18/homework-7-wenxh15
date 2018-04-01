#include <stdlib.h>
#include "swtimer.h"
#include "goertzel.h"
#include "dtmf.h"
#include "display.h"
#include "microphone.h"
#include "hwtimer.h"

unsigned glbListening = 0;

// This ISR is tied to TIMER32_0_BASE and will be called
// at 8 KHz.
// When the application sets glbListing to 1, the ISR
// will record a window of 400 samples of sound, which is
// 50ms of sound at 8KHz. During this window, the DTMF filter
// bank is fed with samples coming from the microphone.
// After 400 samples, the listening phase ends.

void T32_INT1_IRQHandler() {
    unsigned vx;
    static unsigned SamplesListened = 0;
    if (glbListening) {
        vx = GetSampleMicrophone();
        DTMFAddSample(vx);
        SamplesListened++;
        if (SamplesListened == 400) {
            glbListening = 0;
            SamplesListened = 0;
        }
    }
    Timer32_clearInterruptFlag(TIMER32_0_BASE);
}

int main(void) {

    // Initialize device
    InitTimer();
    InitMicrophone();
    InitDisplay();

    Interrupt_enableInterrupt(INT_T32_INT1);
    Interrupt_enableMaster();

    // We start by 'listening' (setting glbListening to 1),
    // which captures a window of 50ms through the ISR,
    // followed by DTMF analysis and display of the
    // resulting power values.
    // Then, the DTMF is reset, and the listening phase
    // restarts.

    glbListening = 1;
    while (1) {
        if (!glbListening) {
            DTMFDisplay();
            DTMFReset();
            glbListening = 1;
        }
    }

}
