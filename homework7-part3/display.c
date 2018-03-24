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

void DrawBoard(tcellstate map[9]) {
    //=============================================================
    // TO BE COMPLETED BY YOU
    // This function draws the playing board for
    // the game state encoded in tcellstate map[9]
    // Each entry of map[] contains the status of
    // one field:
    //
    //     map[0]   |   map[1]   |  map[2]
    //     ---------+------------+--------
    //     map[3]   |   map[4]   |  map[5]
    //     ---------+------------+--------
    //     map[6]   |   map[7]   |  map[8]
    //
    // tcellstate is one of: empty, cross, circle
    //
    // The DrawBoard function needs to draw the gridlines,
    // and places symbols in the grid cells:
    //
    //     tcellstate       symbol
    //       empty
    //       cross            X
    //       circle           O
    //
    // Note that the symbols can be drawn as characters on
    // the LCD: capital 'X' and capital 'O'.














    //=============================================================
}

void DrawWinner(tcellstate map[9], int winner, uint32_t color) {
    //=============================================================
    // TO BE COMPLETED BY YOU
    // This highlights the symbols for the given 'winning code'
    // as computed by CircleWins(map) or CrossWins(map) (see
    // maplogic.c)
    //
    // This function has to be compatible with DrawBoard, because
    // it will only redraw the symbols of a winning row, column
    // or diagonal in a different color. This means that
    // the symbol locations used by DrawWinner have to be the
    // same as those used by DrawBoard









    //=============================================================
}
