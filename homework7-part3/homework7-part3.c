#include <stdlib.h>
#include "maplogic.h"
#include "button.h"
#include "display.h"
#include "hwtimer.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

typedef enum {idle,
              waiting,
              playingcircle,
              playingcross,
              winning,
              waiting2} state_t;

void Process(int b1, int b2) {

    static state_t state = idle;

    // cell map state. As the game proceeds, these
    // locations fill up with crosses and circles
    // until one wins, or it's a tie.
    static tcellstate map[9] = {empty, empty, empty,
                                empty, empty, empty,
                                empty, empty, empty};
    unsigned w;

    switch (state) {

    // Initial state - draw an empty map
    case idle:
        DrawBoard(map);
        state = waiting;
        break;

    // wait for user to press button b1 to initiate autoplay
    case waiting:
        if (b1)
            state = playingcircle;
        break;

    // It's circle's turn to play
    case playingcircle:

        // find a randomlocation available and add a circle
        RandomAdd(map, circle);

        // next turn will be cross playing
        state = playingcross;

        // check if the game is over
        if (CircleWins(map) || Tie(map))
            state = winning;

        // update the playing field
        DrawBoard(map);
        break;

    // It's cross's turn to play
    case playingcross:

        // find a randomlocation available and add a circle
        RandomAdd(map, cross);

        // next turn will be circle playing
        state = playingcircle;

        // check if the game is over
        if (CrossWins(map) || Tie(map))
            state = winning;

        // update the playing field
        DrawBoard(map);
        break;

    // Game is finished. Show the winner
    case winning:

        // Highlight circle winning score
        if (w = CircleWins(map))
            DrawWinner(map, w, GRAPHICS_COLOR_YELLOW);

        // Highlight cross winning score
        if (w = CrossWins(map))
            DrawWinner(map, w, GRAPHICS_COLOR_YELLOW);

        state = waiting2;
        break;

    // Wait for button 2
    case waiting2:

        if (b2) {

            // Button 2 clears the map and starts again
            ClearMap(map);
            DrawBoard(map);
            state = waiting;
        }
        break;
    }
}

int main(void) {

    // init device
    InitTimer();
    InitDisplay();
    InitButtonS1();
    InitButtonS2();

    while (1) {
        // Scan the buttons and send them to the Process FSM
        int b1    = ButtonS1Pressed();
        int b2    = ButtonS2Pressed();
        Process(b1, b2);
    }
}
