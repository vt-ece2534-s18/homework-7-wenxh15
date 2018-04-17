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
    Graphics_drawLineV(&g_sContext,43,0,128);
    Graphics_drawLineV(&g_sContext,86,0,128);
    Graphics_drawLineH(&g_sContext,0,128,43);
    Graphics_drawLineH(&g_sContext,0,128,86);
    // The DrawBoard function needs to draw the gridlines,
    // and places symbols in the grid cells:
    //     tcellstate       symbol
    //       empty
    //       cross            X
    //       circle           O
    //
    // Note that the symbols can be drawn as characters on
    // the LCD: capital 'X' and capital 'O'.
    if (map[0] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 21, 21, OPAQUE_TEXT);
    }
    else if (map[0] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 21, OPAQUE_TEXT);
    }
    else if (map[0] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 21, OPAQUE_TEXT);
    }
    if (map[1] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 64, 21, OPAQUE_TEXT);
    }
    else if (map[1] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 64, 21, OPAQUE_TEXT);
    }
    else if (map[1] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 64, 21, OPAQUE_TEXT);
    }
    if (map[2] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 107, 21, OPAQUE_TEXT);
    }
    else if (map[2] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 107, 21, OPAQUE_TEXT);
    }
    else if (map[2] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 107, 21, OPAQUE_TEXT);
    }
    if (map[3] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 21, 64, OPAQUE_TEXT);
    }
    else if (map[3] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 64, OPAQUE_TEXT);
    }
    else if (map[3] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 64, OPAQUE_TEXT);
    }
    if (map[4] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 64, 64, OPAQUE_TEXT);
    }
    else if (map[4] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 64, 64, OPAQUE_TEXT);
    }
    else if (map[4] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 64, 64, OPAQUE_TEXT);
    }
    if (map[5] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 107, 64, OPAQUE_TEXT);
    }
    else if (map[5] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 107, 64, OPAQUE_TEXT);
    }
    else if (map[5] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 107, 64, OPAQUE_TEXT);
    }
    if (map[6] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 21, 107, OPAQUE_TEXT);
    }
    else if (map[6] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 107, OPAQUE_TEXT);
    }
    else if (map[6] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 107, OPAQUE_TEXT);
    }
    if (map[7] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 64, 107, OPAQUE_TEXT);
    }
    else if (map[7] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 64, 107, OPAQUE_TEXT);
    }
    else if (map[7] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 64, 107, OPAQUE_TEXT);
    }
    if (map[8] == empty)
    {
        Graphics_drawString(&g_sContext, " ", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (map[8] == cross)
    {
        Graphics_drawString(&g_sContext, "X", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (map[8] == circle)
    {
        Graphics_drawString(&g_sContext, "O", 1, 107, 107, OPAQUE_TEXT);
    }
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
    if (winner == 1)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 107, 21, OPAQUE_TEXT);
    }
    else if (winner == 2)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 107, 64, OPAQUE_TEXT);
    }
    else if (winner == 3)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 107, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 107, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (winner == 4)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 21, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 21, 107, OPAQUE_TEXT);
    }
    else if (winner == 5)
    {
        Graphics_drawString(&g_sContext, "X", 1, 64, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 107, OPAQUE_TEXT);
    }
    else if (winner == 6)
    {
        Graphics_drawString(&g_sContext, "X", 1, 107, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 107, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (winner == 7)
    {
        Graphics_drawString(&g_sContext, "X", 1, 21, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (winner == 8)
    {
        Graphics_drawString(&g_sContext, "X", 1, 107, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "X", 1, 21, 107, OPAQUE_TEXT);
    }
    if (winner == 9)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 107, 21, OPAQUE_TEXT);
    }
    else if (winner == 10)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 107, 64, OPAQUE_TEXT);
    }
    else if (winner == 11)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 107, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 107, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (winner == 12)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 21, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 21, 107, OPAQUE_TEXT);
    }
    else if (winner == 13)
    {
        Graphics_drawString(&g_sContext, "O", 1, 64, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 107, OPAQUE_TEXT);
    }
    else if (winner == 14)
    {
        Graphics_drawString(&g_sContext, "O", 1, 107, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 107, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (winner == 15)
    {
        Graphics_drawString(&g_sContext, "O", 1, 21, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 107, 107, OPAQUE_TEXT);
    }
    else if (winner == 16)
    {
        Graphics_drawString(&g_sContext, "O", 1, 107, 21, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 64, 64, OPAQUE_TEXT);
        Graphics_drawString(&g_sContext, "O", 1, 21, 107, OPAQUE_TEXT);
    }
    //=============================================================
}
