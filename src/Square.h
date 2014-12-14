#ifndef Square_H
#define Square_H

#include "ErrorCode.h"

#define C(x)  ((x>0)? 1<<(x-1) : 0x1ff)

typedef struct Square Square;

struct Square {
  int row;
  int column;
};

extern Square rowPeers[9][9][9];
extern Square columnPeers[9][9][9];
extern Square boxPeers[9][9][9];

void clearSquares(int square[9][9]);

int *getSquare(int (square)[9][9], int row, int column);
void squareSetNumber(int *square, int number);
void squareSetNumberForZero(int *square);
void squareDelNumber(int *square, int number);
void removeOthersExcept(int *square, int number);
int isSquareContain(int *square, int number);

void initRowPeers(Square rowPeers[9][9][9]);
void initColPeers(Square columnPeers[9][9][9]);
void initBoxPeers(Square boxPeers[9][9][9]);
int getBeginningIndex(int index);

void eliminateNumberFromAllPeers(int squares[9][9], int row, int column, int value);
void eliminateNumberFromPeers(int squares[9][9], Square *peers, int row, int column, int findNumberToEliminate);
int squareHas(int squares[9][9], int row, int column, int setValue);
int squareContainOneNumbers(int square[9][9], int row, int column);
int squareContainTwoNumbers(int square[9][9], int row, int column);
int squareContainNumbers(int square[9][9], int row, int column);
int checkBinaryValue(int value);
void duplicateSquares(int squares[9][9], int dupSquares[9][9]);
int isSudokuSolved(int squares[9][9]);
Square selectSquareWithLeastValues(int square[9][9]);

void forCheckRowNakedPair(int square[9][9],Square *peers,int j,int temp1);
void forCheckColumnNakedPair(int square[9][9],Square *peers,int j,int temp1);
void forCheckBoxNakedPair(int square[9][9],Square *peers,int temp1);

void eliminateNakedPair(int square[9][9]);
void eliminateNakedPairInPeers(int square[9][9],Square *peers);

void forCheckRowNakedTriples(int square[9][9],Square *peers,int j,int temp1);
void forCheckColumnNakedTriples(int square[9][9],Square *peers,int j,int temp1);
void forCheckBoxNakedTriples(int square[9][9],Square *peers,int temp1);

void eliminateNakedTriples(int square[9][9]);
void eliminateNakedTriplesInPeers(int square[9][9],Square *peers);


void eliminateNakedQuad(int square[9][9]);
void eliminateNakedQuadInPeers(int square[9][9],Square *peers);


void eliminateBruteForce(int squares[9][9]);

void dumpSquare(int square[9][9]);

void searchPosibilityValueOfEmptySquare(int square[9][9]);
void searchPosibilityValueOfEmptySquareInPeers(int square[9][9],Square *peers);


#endif // Square_H

