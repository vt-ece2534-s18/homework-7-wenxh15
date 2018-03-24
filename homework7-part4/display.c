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

void DrawUnsigned(unsigned line, char prefix[4], unsigned n) {
    char buf[13]    = "PPPP XXXXXXXX";
    char hexstr[16] = "0123456789ABCDEF";
    buf[0]  = prefix[0];
    buf[1]  = prefix[1];
    buf[2]  = prefix[2];
    buf[3]  = prefix[3];
    buf[4]  = ' ';
    buf[5]  = hexstr[(n >> 28) & 0xF];
    buf[6]  = hexstr[(n >> 24) & 0xF];
    buf[7]  = hexstr[(n >> 20) & 0xF];
    buf[8]  = hexstr[(n >> 16) & 0xF];
    buf[9]  = hexstr[(n >> 12) & 0xF];
    buf[10] = hexstr[(n >>  8) & 0xF];
    buf[11] = hexstr[(n >>  4) & 0xF];
    buf[12] = hexstr[(      n) & 0xF];
    Graphics_drawStringCentered(&g_sContext, (int8_t *) buf,
                                             13, 64,
                                             16 + (line - 1) * 16,
                                             OPAQUE_TEXT);
}
