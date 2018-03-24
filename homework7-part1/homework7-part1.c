#include <stdlib.h>
#include "swtimer.h"
#include "hwtimer.h"
#include "display.h"
#include "microphone.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

unsigned glbMax = 0;
unsigned glbMin = 0xFFFF;

void T32_INT1_IRQHandler() {

    //=============================================================
    // TO BE COMPLETED BY YOU

    // Upon every timer interrupt, take one sample from the microphone
    // and compare it with the running maximum and minimum

    // If the same is bigger (than the maximum) or smaller
    // (than the minimum), update maximum resp. minimum with the sample value

    // At the end of the ISR, clear the interrupt request from this timer










    //=============================================================
}

int main(void) {

    InitTimer();
    InitMicrophone();
    InitDisplay();

    Interrupt_enableInterrupt(INT_T32_INT1);  // 8KHz for ADC
    Interrupt_enableMaster();

    tSWTimer oneshot500ms;
    InitSWTimer (&oneshot500ms, TIMER32_1_BASE, 1500000);
    StartSWTimer(&oneshot500ms);

    while (1) {
        if (SWTimerOneShotExpired(&oneshot500ms)) {
            DisplayMaxMin(glbMax, glbMin);
            glbMax = 0;
            glbMin = 0xFFFF;
            StartSWTimer(&oneshot500ms);
        }
    }
}
