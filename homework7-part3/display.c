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
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    Graphics_drawLineH(&g_sContext, 19,        109,    49);
    Graphics_drawLineH(&g_sContext, 19,        109,    79);
    Graphics_drawLineV(&g_sContext, 49,        19,     109);
    Graphics_drawLineV(&g_sContext, 79,        19,     109);
    // The DrawBoard function needs to draw the gridlines,
    // and places symbols in the grid cells:
    //     tcellstate       symbol
    //       empty
    //       cross            X
    //       circle           O
    //
    // Note that the symbols can be drawn as characters on
    // the LCD: capital 'X' and capital 'O'.
    int8_t *symbolMap[3] = {" ", "X", "O"};
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_CYAN);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[0]], -1,  32,  32, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[1]], -1,  64,  32, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[2]], -1,  96,  32, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[3]], -1,  32,  64, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[4]], -1,  64,  64, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[5]], -1,  96,  64, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[6]], -1,  32,  96, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[7]], -1,  64,  96, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, symbolMap[map[8]], -1,  96,  96, OPAQUE_TEXT);
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
    int8_t *symbolMap[3] = {" ", "X", "O"};
    Graphics_setForegroundColor(&g_sContext, color);

    switch (winner) {
    case 1: // row 1
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[0]], -1,  32,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[1]], -1,  64,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[2]], -1,  96,  32, OPAQUE_TEXT);
        break;
    case 2: // row 2
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[3]], -1,  32,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[4]], -1,  64,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[5]], -1,  96,  64, OPAQUE_TEXT);
        break;
    case 3: // row 3
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[6]], -1,  32,  96, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[7]], -1,  64,  96, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[8]], -1,  96,  96, OPAQUE_TEXT);
        break;
    case 4: // col 1
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[0]], -1,  32,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[3]], -1,  32,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[6]], -1,  32,  96, OPAQUE_TEXT);
        break;
    case 5: // col 2
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[1]], -1,  64,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[4]], -1,  64,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[7]], -1,  64,  96, OPAQUE_TEXT);
        break;
    case 6: // col 3
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[2]], -1,  96,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[5]], -1,  96,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[8]], -1,  96,  96, OPAQUE_TEXT);
        break;
    case 7: // diagonal
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[0]], -1,  32,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[4]], -1,  64,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[8]], -1,  96,  96, OPAQUE_TEXT);
        break;
    case 8: // back diagonal
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[2]], -1,  96,  32, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[4]], -1,  64,  64, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, symbolMap[map[6]], -1,  32,  96, OPAQUE_TEXT);
        break;
    }
    //=============================================================
}
