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
    unsigned vx;
    vx = GetSampleMicrophone();
    // Upon every timer interrupt, take one sample from the microphone
    // and compare it with the running maximum and minimum
    // If the same is bigger (than the maximum) or smaller
    // (than the minimum), update maximum resp. minimum with the sample value
    if (vx > glbMax)
    {
        glbMax = vx;
    }
    else if (vx < glbMin)
    {
        glbMin = vx;
    }
    // At the end of the ISR, clear the interrupt request from this timer
    Timer32_clearInterruptFlag(TIMER32_0_BASE);
    //=============================================================
}

int main(void) {

    // Device initialization
    InitTimer();
    InitMicrophone();
    InitDisplay();

    // Enable ISR for a TIMER32_BASE_0 overflow at 8KHz
    Interrupt_enableInterrupt(INT_T32_INT1);
    Interrupt_enableMaster();

    // Create a 500ms software timer tied to TIMER32_BASE_0
    tSWTimer oneshot500ms;
    InitSWTimer (&oneshot500ms, TIMER32_1_BASE, 1500000);
    StartSWTimer(&oneshot500ms);

    while (1) {
        // Every 500ms, the software timer overflows
        if (SWTimerOneShotExpired(&oneshot500ms)) {

            // Display the max and min obtained from ADC
            DisplayMaxMin(glbMax, glbMin);
            glbMax = 0;
            glbMin = 0xFFFF;

            // Restart the software timer
            StartSWTimer(&oneshot500ms);
        }
    }
}
