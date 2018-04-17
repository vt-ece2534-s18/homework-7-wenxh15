#include "maplogic.h"
#include <stdlib.h>

// This function returns the winning code when X wins
// There are 8 possible 'winning codes':
//   1 = first row contains 3 X
//   2 = second row contains 3 X
//   3 = third row contains 3 X
//   4 = first column contains 3 X
//   5 = second column contains 3 X
//   6 = third column contains 3 X
//   7 = diagonal contains 3 X
//   8 = antidiagonal contains 3 X
// There is also a non-winning output:
//   0 = No winning combination exists
int CrossWins(tcellstate map[9]) {
    //=============================================================
    // TO BE COMPLETED BY YOU
    // returns the winning code for 'X'
    if ((map[0] == map[1] == map[2] == map[3] == map[4] == map[5] == map[6] == map[7] == map[8]) && (map[0] != empty)){
    if (map[0] == map[1] == map[2] == cross)
    {
        return 1;
    }
    else if (map[3] == map[4] == map[5] == cross)
    {
        return 2;
    }
    else if (map[6] == map[7] == map[8] == cross)
    {
        return 3;
    }
    else if (map[0] == map[3] == map[6] == cross)
    {
        return 4;
    }
    else if (map[1] == map[4] == map[7] == cross)
    {
        return 5;
    }
    else if (map[2] == map[5] == map[8] == cross)
    {
        return 6;
    }
    else if (map[0] == map[4] == map[8] == cross)
    {
        return 7;
    }
    else if (map[2] == map[4] == map[6] == cross)
    {
        return 8;
    }
    }
        return 0;
}

// This function returns the winning code when O wins
// There are 8 possible 'winning codes':
//   1 = first row contains 3 O
//   2 = second row contains 3 O
//   3 = third row contains 3 O
//   4 = first column contains 3 O
//   5 = second column contains 3 O
//   6 = third column contains 3 O
//   7 = diagonal contains 3 O
//   8 = antidiagonal contains 3 O
// There is also a non-winning output:
//   0 = No winning combination exists
int CircleWins(tcellstate map[9]) {
    //=============================================================
    // TO BE COMPLETED BY YOU
    // returns the winning code for 'O'
    if ((map[0] == map[1] == map[2] == map[3] == map[4] == map[5] == map[6] == map[7] == map[8]) && (map[0] != empty)){
    if (map[0] == map[1] == map[2] == circle)
    {
        return 9;
    }
    else if (map[3] == map[4] == map[5] == circle)
    {
        return 10;
    }
    else if (map[6] == map[7] == map[8] == circle)
    {
        return 11;
    }
    else if (map[0] == map[3] == map[6] == circle)
    {
        return 12;
    }
    else if (map[1] == map[4] == map[7] == circle)
    {
        return 13;
    }
    else if (map[2] == map[5] == map[8] == circle)
    {
        return 14;
    }
    else if (map[0] == map[4] == map[8] == circle)
    {
        return 15;
    }
    else if (map[2] == map[4] == map[6] == circle)
    {
        return 16;
    }
    }
        return 0;
}

// This function returns true if there is a tie
// (ie. neither X nor O wins, and there are no empty cells left)
int Tie(tcellstate map[9]) {
    return ((map[0] != empty) &&
            (map[1] != empty) &&
            (map[2] != empty) &&
            (map[3] != empty) &&
            (map[4] != empty) &&
            (map[5] != empty) &&
            (map[6] != empty) &&
            (map[7] != empty) &&
            (map[8] != empty) &&
            (CircleWins(map) == 0)  &&
            (CrossWins (map) == 0));
}

// This function resets map sate to empty
void ClearMap(tcellstate map[9]) {
    map[0] = map[1] = map[2] = empty;
    map[3] = map[4] = map[5] = empty;
    map[6] = map[7] = map[8] = empty;
}

void AbortMap(tcellstate map[9]) {
    unsigned i;
    for (i=0; i<9; i++)
        if (map[i] == empty)
            map[i] = cross;
}

// Adds symbol in a random empty location
void  RandomAdd(tcellstate map[9], tcellstate v) {
   unsigned numempty = 0;
   unsigned done = 0;
   unsigned i;
   for (i=0; i<9; i++)
       if (map[i] == empty)
           numempty++;
   if (numempty == 0)
       return;
   while (!done) {
       i = rand() % 9;
       if (map[i] == empty) {
           map[i] = v;
           done = 1;
       }
   }
}
