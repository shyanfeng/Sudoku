#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"
#include "CException.h"

#define getActualRowForPeers ((peers[i].row) + 1)
#define getActualColumnForPeers ((peers[i].column) + 1)

Square rowPeers[9][9][9];
Square columnPeers[9][9][9];
Square boxPeers[9][9][9];
int dupSquares[9][9];

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
  
  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      int p = 0;
        rowStart = getBeginningIndex(r);
        colStart = getBeginningIndex(c);   
        for(row = rowStart; row < (rowStart + 3) ;row++){
          for(col = colStart; col< (colStart + 3) ;col++){
           
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

void eliminateNumberFromAllPeers(int squares[9][9], int row, int column, int value){
  Square *peersRow = rowPeers[row - 1][column - 1];
  Square *peersColumn = columnPeers[row - 1][column - 1];
  Square *peersBox = boxPeers[row - 1][column - 1];

  eliminateNumberFromPeers(squares, peersRow, row, column, value);
  eliminateNumberFromPeers(squares, peersColumn, row, column, value);
  eliminateNumberFromPeers(squares, peersBox, row, column, value);

 }

void eliminateNumberFromPeers(int squares[9][9], Square *peers, int row, int column, int findNumberToEliminate){
  int i,c;  
  int storeSquareValue;
  int value;
  int decimalValue;
  int value1 = squareHas(squares, row, column, findNumberToEliminate);
  
  if((squareContainTwoNumbers(squares, row, column) == 1) && (value1 == 1)){
    int *storeFixValue = getSquare(squares, row, column);
    squareDelNumber(storeFixValue, findNumberToEliminate);
    value = *storeFixValue;
    decimalValue  = checkBinaryValue(value);
  }else{
    decimalValue = checkBinaryValue(*getSquare(squares, row, column));
  }
  
  for(i = 0; i < 9; i++){
    int getSquareHasReturnValue = squareHas(squares, getActualRowForPeers, getActualColumnForPeers, decimalValue);
    if(getSquareHasReturnValue == 1){
      if((row - 1) == peers[i].row && (column - 1) == peers[i].column){
        int *value2 = getSquare(squares, getActualRowForPeers, getActualColumnForPeers);
        squareSetNumber(value2, decimalValue);
      }else{
        int *value2 = getSquare(squares, getActualRowForPeers, getActualColumnForPeers);
        squareDelNumber(value2, decimalValue);
        int value1 = *value2;
        if(value1 == 0){
          // printf("halo");
          Throw(ERR_EMPTY_SQU);
        }else if(squareContainOneNumbers(squares, getActualRowForPeers, getActualColumnForPeers) == 1){
          int value2 = checkBinaryValue(value1);
          eliminateNumberFromAllPeers(squares, getActualRowForPeers, getActualColumnForPeers, value2);
        }
      }
    }
  }
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

int squareContainTwoNumbers(int square[9][9], int row, int column){
  int getValueFromTemp1;
  getValueFromTemp1 = squareContainNumbers(square, row, column);  

  if(getValueFromTemp1 == 2){
    return 1;
  }else{
    return 0;
  }  
}

int squareContainOneNumbers(int square[9][9], int row, int column){
  int getValueFromTemp1;
  getValueFromTemp1 = squareContainNumbers(square, row, column);

  if(getValueFromTemp1 == 1){
    return 1;
  }else{
    return 0;
  }  
}

int squareContainNumbers(int square[9][9], int row, int column){
  int i;   
  int *value; 
  value = getSquare(square, row, column);
  int value1 = *value;
  int temp1 = 0;
    
  for(i = 0; i < 9; i++){
    int temp = value1 & 1;
    if(temp == 1){
      temp1 = temp1 + temp;
    }
    value1 = value1>>1;
  } 
    
  int getValueFromTemp1 = temp1;  
  
  return getValueFromTemp1;
}

int squareHas(int squares[9][9], int row, int column, int setValue){
  int getValueFromSquare;
  int *squarePtr;
  squarePtr = getSquare(squares, row, column);
  getValueFromSquare = *squarePtr;

  int value1 = C(setValue);

  if(getValueFromSquare == 0x1ff){
    getValueFromSquare = 0x000;
  }
  
  int value2 = getValueFromSquare & value1;

  if(value2 == value1){
    return 1;
  }else{
    return 0;
  }
}

void duplicateSquares(int squares[9][9], int dupSquares[9][9]){
  int r, c;
  
  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      dupSquares[r][c] = squares[r][c];
    }
  }

}

int isSudokuSolved(int squares[9][9]){
  int r,c;
  int value = 0;
  int temp = 0x01;
  for(r = 0; r < 9 ; r++){
    for(c = 0; c < 9 ; c++){
      value = squareContainOneNumbers(squares,(r)+1,(c)+1);   
      temp  = value & temp;
    }
  }
      if(temp == 1){
        return 1;
      }else{
        return 0;
      }

}

void bruteForce(int squares[9][9]){
  int r, c;
  int num = 0x01;;
  int checkForContainTwoNumber;
  int *randomChooseOneNumber;
  int *backToDupSquares;
  int newA;
  int i;
  int f;
  int b;
  ErrorCode e;
  
  duplicateSquares(squares, dupSquares);
  
  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      checkForContainTwoNumber = squareContainNumbers(squares, (r + 1), (c + 1));
      if(checkForContainTwoNumber == 2){
        randomChooseOneNumber = getSquare(squares, r + 1, c + 1);
        int a = *randomChooseOneNumber;
        
        for(i = 0; i < 9; i++){
          f = a & (num << i); 
          if(f != 0){
            b = checkBinaryValue(f);
            Try{
              // printf("a = %d\n", a & (num << i));
              eliminateNumberFromAllPeers(squares, (r + 1), (c + 1), b);
            }Catch(e){
              printf("r= %d, c=%d, f = %d\n", r, c,f);
              backToDupSquares = getSquare(dupSquares, r + 1, c + 1);
              newA = *backToDupSquares;
              f = newA & ~f;
              // printf("f = %d\n", f);
              
            }
            
            // printf("f = %d\n", f);
            if(f == (a & (num << i))){
              a = 0;
              printf("aaa\n");
            }else if(f == (newA & ~f)){
              // a = f;
              // printf("bbb");
            }
          }
        }
        
        /*if(f == 0){
          r = r - 1;
          c = c - 1;
        }*/
      }
    }
  }
}

