#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <ti/grlib/grlib.h>

void InitDisplay  ();
void DrawUnsigned (unsigned line, char prefix[4], unsigned n);

#endif /* DISPLAY_H_ */
