#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "maplogic.h"
#include <ti/grlib/grlib.h>

void InitDisplay();
void DrawBoard  (tcellstate map[9]);
void DrawWinner (tcellstate map[9],int winner, uint32_t color);


#endif /* DISPLAY_H_ */
