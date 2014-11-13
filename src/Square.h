#ifndef Square_H
#define Square_H

#include "ErrorCode.h"

#define C(x)  (x>0)? 1<<(x-1) : 0x1ff

typedef struct Square Square;

struct Square {
  int row;
  int column;
};
void delslot(int size, int array[][size], int r, int c);
int *getSquare(int (*square)[9][9], int row, int column);
void squareSetNumber(int *square, int number);
void squareDelNumber(int *square, int number);
void removeOthersExcept(int *square, int number);
int isSquareContain(int *square, int number);
void eliminateNeighbouringSquaresOf(int (*square)[9][9], int number);

#endif // Square_H

