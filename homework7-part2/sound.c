#include "sound.h"
#include "hwtimer.h"
#include "swtimer.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

// This configuration sets a 50% duty cycle configuration
// for CCR4. You will have to figure out what Timer_A module
// drives the buzzer. pin TA0.4 is driving the
// buzzer. The Timer_A module then is 0.

Timer_A_PWMConfig pwmConfig_A4 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 440.00),         // A4
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 440.00)
};

Timer_A_PWMConfig pwmConfig_B4 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 493.88),         // B4
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 493.88)
};

Timer_A_PWMConfig pwmConfig_G4 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 392.00),         // G4
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 392.00)
};

Timer_A_PWMConfig pwmConfig_C5 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 523.25),         // C5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 523.25)
};

Timer_A_PWMConfig pwmConfig_D5 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 587.33),         // D5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 587.33)
};

Timer_A_PWMConfig pwmConfig_E5 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 659.25),         // E5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 659.25)
};

Timer_A_PWMConfig pwmConfig_F5 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 698.42),         // F5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 698.42)
};

Timer_A_PWMConfig pwmConfig_Fs5 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 739.99),         // F#5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 739.99)
};

Timer_A_PWMConfig pwmConfig_G5 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 789.99),         // G5
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 789.99)
};

Timer_A_PWMConfig pwmConfig_C6 = {
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        (int) (SYSTEMCLOCK / 1046.50),         // C6
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        (int) ((SYSTEMCLOCK/2) / 1046.50)
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
    static tSWTimer length;
    bool swTimerExpired;
    InitSWTimer(&length, TIMER32_1_BASE, ms * (SYSTEMCLOCK/1000));
    // Play note n for ms milliseconds.
    StartSWTimer(&length);
    swTimerExpired = SWTimerOneShotExpired(&length);
    while (!swTimerExpired)
    {
        swTimerExpired = SWTimerOneShotExpired(&length);
    }
    if (n == note_silent)
    {
        Timer_A_stopTimer(TIMER_A0_BASE);
    }
    else if (n == note_a4)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_A4);
    }
    else if (n == note_b4)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_B4);
    }
    else if (n == note_g4)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_G4);
    }
    else if (n == note_c5)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_C5);
    }
    else if (n == note_d5)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_D5);
    }
    else if (n == note_e5)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_E5);
    }
    else if (n == note_f5)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_F5);
    }
    else if (n == note_fs5)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_Fs5);
    }
    else if (n == note_g5)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_G5);
    }
    else if (n == note_c6)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig_C6);
    }
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
