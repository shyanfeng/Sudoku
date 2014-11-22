#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"

Square rowPeers[9][9][9];
Square columnPeers[9][9][9];
Square boxPeers[9][9][9];

int *getSquare(int (square)[9][9], int row, int column){
  return &(square[row-1][column-1]);
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
  int r, c, rowStart, colStart,row,col;
  int i,j;
  
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){
      int p=0;
        rowStart = getBeginningIndex(r);
        colStart = getBeginningIndex(c);   
        for(row = rowStart; row < (rowStart+3) ;row++){
          for(col = colStart; col< (colStart+3) ;col++){
           
            boxPeers[r][c][p].row = row+1;
            boxPeers[r][c][p++].column = col+1;
          
        }
      }
    }
  }

}


int getBeginningIndex(int index){
  if(index >= 0 && index <= 2){
    return 0;
  }else if(index >= 3 && index <= 5){
    return 3;
  }else if(index >= 6 && index <= 8){
    return 6;
  }else
    printf("out of range");
}


void eliminateNumberFromPeers(int square[9][9],Square *peers,int row,int column,int findNumberToEliminate){
    int r,c;
    for(r=0;r<9;r++){
      if(squareHas(square,peers[r].row,column,findNumberToEliminate) == 1){
          // del
      }
    }
    
    for(c=0;c<9;c++){
      if(squareHas(square,row,peers[c].column,findNumberToEliminate) == 1){
        // del
      }
    }
    
    for(r=row;r<(row+3);r++){
      for(c=0;c<(column+3);c++){
        if(squareHas(square,peers[r].row,peers[c].column,findNumberToEliminate) == 1){
          // del
        }
      }
    }
}



int squareHas(int squares[9][9],int row,int column,int setValue){
  int getValueFromSquare;
  int *squarePtr;
  squarePtr = getSquare(squares, row, column);
  getValueFromSquare = *squarePtr;
//  *squarePtr = 6;
  if(getValueFromSquare == setValue){
    return 1;
  }else{
    return 0;
  }
}
