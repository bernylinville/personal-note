#ifndef AUTOSOLVE
#define AUTOSOLVE

#include "hanoi.h"

void Autosolve(int tower[NumPins][NumDisks]);
void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to);

#endif
