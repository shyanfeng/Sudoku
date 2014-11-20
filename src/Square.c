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

void initRowPeers(Square rowPeers[9][9][9]){
  int r, c, p;

  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      for(p = 0; p < 9; p++){
        rowPeers[r][c][p].row = p;
        rowPeers[r][c][p].column = c;
      }
    }
  }
}

void initColPeers(Square columnPeers[9][9][9]){
  int r, c, p;

  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      for(p = 0; p < 9; p++){
        columnPeers[r][c][p].row = r;
        columnPeers[r][c][p].column = p;
      }
    }
  }
}

void initBoxPeers(Square boxPeers[9][9][9]){
  int r, c, p, rowStart, colStart;
  
  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      for(p = 0; p < 9; p++){
        for(rowStart = r; rowStart < r+3; rowStart++){
          for(colStart = c; colStart < c+3; colStart++){
            boxPeers[r][c][p].row = r;
            boxPeers[r][c][p].column = c;
          }
        }
      }
    }
  }

}

// void eliminateNeighbouringSquaresOf(int *square, int number){
  // int r, c, i, rowStart, colStart;
  
  // row
  // for(r = 0; r < 9; r++){
    // for(c = 0; c < 9; c++){
      // for(i = 0; i < 9; i++){
        // rowPeers[r][c][i].row = *square;
        // printf("%d", rowPeers[r][c][i].row);
        // rowPeers[r][c][i].column = *square;
      // }
    // }
  // }
  
  // rowPeers[r][c] = (*square);

  // /*
  // column
   // for(c = 0; c < 9; c++){
    // for(r = 0; r < 9; r++){
      // for(i = 0; i < 9; i++){
        // boxPeers[r][c][i].row;
        // boxPeers[r][c][i].column;
      // }
    // }
  // }*/
  
  // /*
  // box
   // for(r = 0; r < 9; r++){
    // for(c = 0; c < 9; c++){
      // for(i = 0; i < 9; i++){
        // for(rowStart = r; r < rowStart+3; r++;){
          // for(colStart = c; c < colStart + 3; c++){
          
          // }
        // }
      // }
    // }
  // }*/
  
  // Square *peerSquares = rowPeers[r][c];
  // for(i = 0; i < 9; i++){
    // printf("%d, %d\n", peerSquares[i].row, peerSquares[i].column);
  // }
  
  // /*int i, j;
  
  // for(i = 0; i < 9; i++){
    // if(isSquareContain(square[i][9], number) == 0){
      // squareSetNumber(getSquare());
    // }else
  // }*/
// }