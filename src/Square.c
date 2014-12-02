#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"

Square rowPeers[9][9][9];
Square columnPeers[9][9][9];
Square boxPeers[9][9][9];

void clearSquares(int square[9][9]){
  int i,j;
  
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      square[i][j] = 0;
    }
  }
}

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
  int r, c, rowStart, colStart, row, col;
  int i, j;
  
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){
      int p = 0;
        rowStart = getBeginningIndex(r);
        colStart = getBeginningIndex(c);   
        for(row = rowStart; row < (rowStart+3) ;row++){
          for(col = colStart; col< (colStart+3) ;col++){
           
            boxPeers[r][c][p].row = row;
            boxPeers[r][c][p++].column = col;
          
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

void eliminateNumberFromPeers(int squares[9][9], Square *peers, int row, int column, int findNumberToEliminate){
  int i,c;  int storeSquareValue;
      int *storeFixValue = getSquare(squares,row,column);
      squareDelNumber(storeFixValue,findNumberToEliminate);
      
      int value = *storeFixValue;
      int value1 = checkBinaryValue(value);
      
      if((value != 0) && (squareContainNumbers(squares,row,column) == 1)){
        for(i = 0; i < 9; i++){ 
           int getSquareHasReturnValue = squareHas(squares, ((peers[i].row)+1), ((peers[i].column)+1), value1);    
              if(getSquareHasReturnValue == 1){
                if((row - 1) == peers[i].row && (column - 1) == peers[i].column){
                  squareSetNumber(storeFixValue,value1);
                }else{
                  int *value2 = getSquare(squares,((peers[i].row)+1),((peers[i].column)+1));
                  squareDelNumber(value2,value1);
                  storeSquareValue = *value2;
                  if(storeSquareValue == 0){
                    printf("Throw");
                  }else{
                    if(squareContainNumbers(squares,((peers[i].row)+1),((peers[i].column)+1)) == 1){
                      eliminateNumberFromPeers(squares,peers, peers[i].row, peers[i].column,findNumberToEliminate);
                    }
                  }
                }
            }
            
          }
      }
  
  // int r ,c;  
  // int *storeFixValue = getSquare(squares,row,column);
   
  // for(r = 0; r < 9; r++){  
    // printf("r:%d c:%d \n",peers[r].row, peers[r].column);
    // int getSquareHasReturnValue = squareHas(squares, ((peers[r].row)+1), ((peers[r].column)+1), findNumberToEliminate);
      // if(getSquareHasReturnValue == 1){
        // int *value = getSquare(squares,((peers[r].row)+1),((peers[r].column)+1));
        // squareDelNumber(value,findNumberToEliminate);
      // }
  // }
  // squareSetNumber(storeFixValue,findNumberToEliminate);
}

int checkBinaryValue(int value){
  if(value == 1){
    return 1;
  }else if(value == 2){
    return 2;
  }else if(value == 4){
    return 3;
  }else if(value == 8){
    return 4;
  }else if(value == 16){
    return 5;
  }else if(value == 32){
    return 6;
  }else if(value == 64){
    return 7;
  }else if(value == 128){
    return 8;
  }else if(value == 256){
    return 9;
  } 

}


int squareContainNumbers(int square[9][9],int row,int column){
    int i;   int *value; 
    
    value = getSquare(square,row,column);
    int value1 = *value;
    
    int temp1 = 0;
    
    for(i=0;i<9;i++){
      int temp = value1 & 1;
      if(temp == 1){
        temp1 = temp1 + temp;
      }
      value1 = value1>>1;
    } 
    
    int getValueFromTemp1 = temp1;  

    if(getValueFromTemp1 == 1){
      return 1;
    }else{
      return 0;
    }  
}

int squareHas(int squares[9][9],int row,int column,int setValue){
  int getValueFromSquare;
  int *squarePtr;
  squarePtr = getSquare(squares, row, column);
  getValueFromSquare = *squarePtr;

  int value1 = C(setValue);
  int value2 = getValueFromSquare & value1;

  if(value2 == value1){
    return 1;
  }else{
    return 0;
  }
}
