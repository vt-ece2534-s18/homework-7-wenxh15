#include <stdlib.h>
#include "maplogic.h"
#include "button.h"
#include "display.h"
#include "hwtimer.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

typedef enum {idle, waiting, playingcircle, playingcross, winning, waiting2} state_t;

void Process(int b1, int b2) {
    static state_t state = idle;
    static tcellstate map[9] = {empty, empty, empty,
                                empty, empty, empty,
                                empty, empty, empty};
    unsigned w;

    switch (state) {
    case idle:
        DrawBoard(map);
        state = waiting;
        break;
    case waiting:
        if (b1)
            state = playingcircle;
        break;
    case playingcircle:
        RandomAdd(map, circle);
        state = playingcross;
        if (CircleWins(map) || Tie(map))
            state = winning;
        DrawBoard(map);
        break;
    case playingcross:
        RandomAdd(map, cross);
        state = playingcircle;
        if (CrossWins(map) || Tie(map))
            state = winning;
        DrawBoard(map);
        break;
    case winning:
        if (w = CircleWins(map))
            DrawWinner(map, w, GRAPHICS_COLOR_YELLOW);
        if (w = CrossWins(map))
            DrawWinner(map, w, GRAPHICS_COLOR_YELLOW);
        state = waiting2;
        break;
    case waiting2:
        if (b2) {
            ClearMap(map);
            DrawBoard(map);
            state = waiting;
        }
        break;
    }
}

int main(void) {

    InitTimer();
    InitDisplay();
    InitButtonS1();
    InitButtonS2();

    while (1) {
        int b1    = ButtonS1Pressed();
        int b2    = ButtonS2Pressed();
        Process(b1, b2);
    }
}
