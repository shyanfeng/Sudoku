#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"

Square rowPeers[9][9][9];
Square columnPeers[9][9][9];
Square boxPeers[9][9][9];

int *getSquare(int (*square)[9][9], int row, int column){
	return &((*square)[row-1][column-1]);
} 

void squareSetNumber(int *square, int number){
  (*square) = (*square) | (C(number));
}

void squareDelNumber(int *square, int number){
  (*square) = (*square) & (~(1 <<(number - 1)));
}

void removeOthersExcept(int *square, int number){
  (*square) = (*square) & (1 <<(number - 1));
}

int isSquareContain(int *square, int number){
  if((*square) == (1 <<(number - 1))){
    return 1;
  }else{
    return 0;
  }
}

void eliminateNeighbouringSquaresOf(int (*square)[9][9], int number){
  int r, c, i, rowStart, colStart;
  
  //row
  for(r = 0; r < 9; r++){
    for(c = 0; r < 9; r++){
      for(i = 0; i < 9; i++){
        boxPeers[r][c][i].row;
        boxPeers[r][c][i].column;
      }
    }
  }
  /*
  //column
   for(c = 0; c < 9; c++){
    for(r = 0; r < 9; r++){
      for(i = 0; i < 9; i++){
        boxPeers[r][c][i].row;
        boxPeers[r][c][i].column;
      }
    }
  }*/
  
  /*
  //box
   for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      for(i = 0; i < 9; i++){
        for(rowStart = r; r < rowStart+3; r++;){
          for(colStart = c; c < colStart + 3; c++){
          
          }
        }
      }
    }
  }*/
  
  Square *peerSquares = rowPeers[4][0];
  for(i = 0; i < 9; i++){
    printf("%d, %d\n", peerSquares[i].row, peerSquares[i].column);
  }
  
  /*int i, j;
  
  for(i = 0; i < 9; i++){
    if(isSquareContain(square[i][9], number) == 0){
      squareSetNumber(getSquare());
    }else
  }*/
}