#include <stdlib.h>
#include "swtimer.h"
#include "goertzel.h"
#include "dtmf.h"
#include "display.h"
#include "microphone.h"
#include "hwtimer.h"

unsigned glbListening = 0;

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
    InitTimer();
    InitMicrophone();
    InitDisplay();

    Interrupt_enableInterrupt(INT_T32_INT1);  // 8KHz for ADC
    Interrupt_enableMaster();

    glbListening = 1;
    while (1) {
        if (!glbListening) {
            DTMFDisplay();
            DTMFReset();
            glbListening = 1;
        }
    }

}
