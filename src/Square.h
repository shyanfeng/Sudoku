#ifndef Square_H
#define Square_H

#include "ErrorCode.h"

#define C(x)  (x>0)? 1<<(x-1) : 0x1ff



typedef struct Square Square;


struct Square {
  int row;
  int column;
};

extern Square rowPeers[9][9][9];
extern Square columnPeers[9][9][9];
extern Square boxPeers[9][9][9];


int *getSquare(int (*square)[9][9], int row, int column);
void squareSetNumber(int *square, int number);
void squareDelNumber(int *square, int number);
void removeOthersExcept(int *square, int number);
int isSquareContain(int *square, int number);

void initRowPeers(Square rowPeers[9][9][9]);
void initColPeers(Square columnPeers[9][9][9]);
void initBoxPeers(Square boxPeers[9][9][9]);
int getBeginningIndex(int index);

void eliminateNumberFromPeers(int square[9][9],Square *peers,int findNumberToEliminate);
int squareHas(int (*square)[9][9],int row,int column,int setValue);
//void eliminateNeighbouringSquaresOf(int *square, int number);

#endif // Square_H

