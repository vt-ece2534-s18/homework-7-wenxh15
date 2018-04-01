#include "sound.h"
#include "hwtimer.h"
#include "swtimer.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

// This configuration sets a 50% duty cycle configuration
// for CCR4. You will have to figure out what Timer_A module
// drives the buzzer, i.e. what pin TAx.4 is driving the
// buzzer. The Timer_A module then is x.

Timer_A_PWMConfig pwmConfig = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 523.25),         // C5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 523.25)
};


void InitSound() {

    // This function switches the IC pin connected to
    // the buzzer from GPIO functionality to Timer_A functionality
    // so that we can drive it with PWM.

    GPIO_setAsPeripheralModuleFunctionOutputPin(
            GPIO_PORT_P2,
            GPIO_PIN7,
            GPIO_PRIMARY_MODULE_FUNCTION);
}

void PlaySound(tnote n, unsigned ms) {

    //=============================================================
    // TO BE COMPLETED BY YOU

    // Play note n for ms milliseconds.

    // You have to use the PWM setting of the Timer_A
    // peripheral that drives the buzzer to sound it

    // The delay ms is generated using a software timer
    // (different from Timer_A!)

    // PlaySound can be implemented as a blocking function.
    // That means that the function turns on the PWM
    // generation, then waits for ms milliseconds, then
    // turns the PWM generation off again.











    //=============================================================

}
