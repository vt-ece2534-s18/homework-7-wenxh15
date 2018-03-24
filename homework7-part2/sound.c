#include "sound.h"
#include "swtimer.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

Timer_A_PWMConfig pwmConfig = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,    // 3 MHz
        (int) (3000000 / 523.25),         // C5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) (1500000 / 523.25)
};

void InitSound() {
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
