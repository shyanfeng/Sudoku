#ifndef Square_H
#define Square_H

#include "ErrorCode.h"

#define C(x)  (x>0)? 1<<(x-1) : 0x1ff

int *getSquare(int (*square)[9][9], int column, int row);
void squareSetNumber(int *square, int number);
void squareDelNumber(int *square, int number);
void eliminateNeighbouringSquaresOf(int (*square)[9][9], int number);

#endif // Square_H
