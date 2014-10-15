#ifndef Square_H
#define Square_H

#define C(x)  (x>0)? 1<<(x-1) : 0x1ff

int *getSquare(int (*square)[][9], int column, int row);
void squareSetNumber(int *getSquare, int number);
void squareDelNumber(int *square);
int eliminateNeighbouringSquaresOf(int *square, int number);

#endif // Square_H
