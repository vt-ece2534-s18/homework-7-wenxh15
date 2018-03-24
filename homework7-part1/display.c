#include "display.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"

Graphics_Context g_sContext;

void InitDisplay() {
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
    Graphics_initContext(&g_sContext,
                         &g_sCrystalfontz128x128,
                         &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_CYAN);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_PURPLE);
    Graphics_setFont(&g_sContext, &g_sFontCmtt16);
    Graphics_clearDisplay(&g_sContext);
}

void DisplayMaxMin(unsigned max, unsigned min) {
    char maxstr[ 9] = "MAX: XXXX";
    char minstr[ 9] = "MIN: XXXX";
    char hexstr[16] = "0123456789ABCDEF";
    maxstr[5] = hexstr[(max >> 12) & 0xF];
    maxstr[6] = hexstr[(max >>  8) & 0xF];
    maxstr[7] = hexstr[(max >>  4) & 0xF];
    maxstr[8] = hexstr[(max      ) & 0xF];
    minstr[5] = hexstr[(min >> 12) & 0xF];
    minstr[6] = hexstr[(min >>  8) & 0xF];
    minstr[7] = hexstr[(min >>  4) & 0xF];
    minstr[8] = hexstr[(min      ) & 0xF];

    Graphics_drawStringCentered(&g_sContext, (int8_t *) maxstr, 9,  64,  50, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, (int8_t *) minstr, 9,  64,  70, OPAQUE_TEXT);
}

