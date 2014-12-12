#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"
#include "CException.h"

#define getActualRowForPeers ((peers[i].row) + 1)
#define getActualColumnForPeers ((peers[i].column) + 1)
#define actualRow (r + 1)
#define actualColumn (c + 1)

Square rowPeers[9][9][9];
Square columnPeers[9][9][9];
Square boxPeers[9][9][9];

ErrorCode e;

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

  if((squareContainNumbers(squares, row, column) == 2) && (value1 == 1)){
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
        int value = *value2;
      }else{
        int *value2 = getSquare(squares, getActualRowForPeers, getActualColumnForPeers);
        // duplicateSquares(squares, dupSquares);
        squareDelNumber(value2, decimalValue);
        int value1 = *value2;
        if(value1 == 0){
          Throw(ERR_EMPTY_SQU);
        }else if(squareContainOneNumbers(squares, getActualRowForPeers, getActualColumnForPeers) == 1){
          int value2 = checkBinaryValue(value1);
          eliminateNumberFromAllPeers(squares, getActualRowForPeers, getActualColumnForPeers, value2);
        } else {
       }
      }
    }
  }

}

Square selectSquareWithLeastValues(int square[9][9]){
	int r, c;
  int count = 10;
  int *getValuePtr;
  int getValue;
  Square sq;
  int returnCount;
	
	for(r = 0; r < 9; r++){
		for(c = 0; c < 9; c++){
      getValuePtr = getSquare(square, r + 1, c + 1);
      getValue = *getValuePtr;
      returnCount = squareContainNumbers(square, r + 1 , c + 1);
      if(returnCount != 1){
        if(returnCount < count){
          sq.row = r;
          sq.column = c;
          count = returnCount;
        }
      }
		}
	}
  return sq;
}

void eliminateNakedPair(int square[9][9]){
  int r,c;
  for(r=0;r<9;r++){
    for(c=0;c<9;c++){
        Square *peersRow = rowPeers[r][c];
        Square *peersColumn = columnPeers[r][c];        
        Square *peersBox = boxPeers[r][c];
        eliminateNakedPairInPeers(square,peersRow);
        eliminateNakedPairInPeers(square,peersColumn);
        eliminateNakedPairInPeers(square,peersBox);
    }
  }
}

void eliminateNakedPairInPeers(int square[9][9],Square *peers){
  int i,j,k,m,n;
  int *tempPtr,*tempPtr1,*tempPtr4;
  int temp,temp1,temp2,temp3;
  int conv = 0x01;
  int storeVal;
  int store3;
  
  //check 2 number and match
  for(i=0;i<9;i++){
     for(j=i+1;j<9;j++){
    if(squareContainTwoNumbers(square,peers[i].row+1,peers[i].column+1) == 1 && squareContainTwoNumbers(square,peers[j].row+1,peers[j].column+1) == 1 ){   
        tempPtr = getSquare(square,peers[i].row+1,peers[i].column+1);
        temp = *tempPtr;
        tempPtr1 = getSquare(square,peers[j].row+1,peers[j].column+1);
        temp1 = *tempPtr1;
        if(temp == temp1){
          temp2 = temp;
        }
    }
    }
  }

  for(k=0;k<9;k++){
    int *tempPtr3;
    tempPtr3 = getSquare(square,peers[k].row+1,peers[k].column+1);
    temp3 = *tempPtr3;
    
    //check if sameValue equal with whole row col or box
      if(temp3 == temp2){
        for(m=0;m<9;m++){
          int value = temp3 &(conv<<m);
          if(value != 0){
            int decimal = checkBinaryValue(value);
            squareSetNumber(tempPtr3,decimal);
          }
        }
      }
      
      else{
          if(squareContainOneNumbers(square,peers[k].row+1,peers[k].column+1) == 1){
              int decimal = checkBinaryValue(temp3);
              squareSetNumber(tempPtr3,decimal);
          }
          
          else if((temp3&temp2) == 0){
            for(m=0;m<9;m++){
            int value = temp3 &(conv<<m);
              if(value != 0){
                int decimal = checkBinaryValue(value);
                squareSetNumber(tempPtr3,decimal);
              }
            }
          }
          
          else{
            for(m=0;m<9;m++){
              int store1 = temp3 & (conv<<m);
              int store2 = temp2 & (conv<<m);
                if(store1 == store2){
                  store3 = store1;
                }else{
                  store1 = 0;
                  store3 = store1;
                }
                int value = store3 &(conv<<m);
                if(value != 0){
                  int decimal = checkBinaryValue(value);
                  squareDelNumber(tempPtr3,decimal);
                }
              
            }
          } 
          
      }
    }
    
  }
  
void eliminateNakedTriples(int square[9][9]){
  int r,c;
  for(r=0;r<9;r++){
    for(c=0;c<9;c++){
        Square *peersRow = rowPeers[r][c];
        Square *peersColumn = columnPeers[r][c];        
        Square *peersBox = boxPeers[r][c];
        eliminateNakedTriplesInPeers(square,peersRow);
        eliminateNakedTriplesInPeers(square,peersColumn);
        eliminateNakedTriplesInPeers(square,peersBox);
    }
  }
}
  
void eliminateNakedTriplesInPeers(int square[9][9],Square *peers){
  int i,j,k,m,n;
  int *tempPtr,*tempPtr1,*tempPtr4;
  int temp,temp1,temp2,temp3;
  int conv = 0x01;
  int storeVal;
  int store3;
  int c;
  int a = 0;
  //check 3 number and match
  for(i=0;i<9;i++){
     for(j=i+1;j<9;j++){
    if(squareContainNumbers(square,peers[i].row+1,peers[i].column+1) == 3 && squareContainNumbers(square,peers[j].row+1,peers[j].column+1) == 3){   
        tempPtr = getSquare(square,peers[i].row+1,peers[i].column+1);
        temp = *tempPtr;
        tempPtr1 = getSquare(square,peers[j].row+1,peers[j].column+1);
        temp1 = *tempPtr1;
        if(temp == temp1){
          temp2 = temp;     
        }
    }
    }
  }
  


  for(k=0;k<9;k++){
    int *tempPtr3;
    tempPtr3 = getSquare(square,peers[k].row+1,peers[k].column+1);
    temp3 = *tempPtr3;
    // check if sameValue equal with whole row col or box
      if(temp3 == temp2){
        for(m=0;m<9;m++){
          int value = temp3 &(conv<<m);
          if(value != 0){
            int decimal = checkBinaryValue(value);
            squareSetNumber(tempPtr3,decimal);
          }
        }
      }
      
      else{
          if(squareContainOneNumbers(square,peers[k].row+1,peers[k].column+1) == 1){
              int decimal = checkBinaryValue(temp3);
              squareSetNumber(tempPtr3,decimal);
          }
          
          else if((temp3&temp2) == 0){
            for(m=0;m<9;m++){
            int value = temp3 &(conv<<m);
              if(value != 0){
                int decimal = checkBinaryValue(value);
                squareSetNumber(tempPtr3,decimal);
              }
            }
          }
          
          else{
            for(m=0;m<9;m++){
              int store1 = temp3 & (conv<<m);
              int store2 = temp2 & (conv<<m);
                if(store1 == store2){
                  store3 = store1;
                }else{
                  store1 = 0;
                  store3 = store1;
                }
                int value = store3 &(conv<<m);
                if(value != 0){
                  int decimal = checkBinaryValue(value);
                  squareDelNumber(tempPtr3,decimal);
                  int check = *tempPtr3;
                  if(check == 0){
                    Throw(ERR_EMPTY_SQU);
                  }
                }
              
            }
          } 
          
      }
    }
    
  }

void eliminateNakedQuad(int square[9][9]){
  int r,c;
  for(r=0;r<9;r++){
    for(c=0;c<9;c++){
        Square *peersRow = rowPeers[r][c];
        Square *peersColumn = columnPeers[r][c];        
        Square *peersBox = boxPeers[r][c];
        eliminateNakedQuadInPeers(square,peersRow);
        eliminateNakedQuadInPeers(square,peersColumn);
        eliminateNakedQuadInPeers(square,peersBox);
    }
  }
}
  
void eliminateNakedQuadInPeers(int square[9][9],Square *peers){
  int i,j,k,m,n;
  int *tempPtr,*tempPtr1,*tempPtr4;
  int temp,temp1,temp2,temp3;
  int conv = 0x01;
  int storeVal;
  int store3;
  int c;
  int a = 0;

  for(i=0;i<9;i++){
     for(j=i+1;j<9;j++){
    if(squareContainNumbers(square,peers[i].row+1,peers[i].column+1) == 4 && squareContainNumbers(square,peers[j].row+1,peers[j].column+1) == 4){   
        tempPtr = getSquare(square,peers[i].row+1,peers[i].column+1);
        temp = *tempPtr;
        tempPtr1 = getSquare(square,peers[j].row+1,peers[j].column+1);
        temp1 = *tempPtr1;
        if(temp == temp1){
          temp2 = temp; 
        }
    }
    }
  }
  


  for(k=0;k<9;k++){
    int *tempPtr3;
    tempPtr3 = getSquare(square,peers[k].row+1,peers[k].column+1);
    temp3 = *tempPtr3;
      if(temp3 == temp2){
        for(m=0;m<9;m++){
          int value = temp3 &(conv<<m);
          if(value != 0){
            int decimal = checkBinaryValue(value);
            squareSetNumber(tempPtr3,decimal);
          }
        }
      }
      
      else{
          if(squareContainOneNumbers(square,peers[k].row+1,peers[k].column+1) == 1){
              int decimal = checkBinaryValue(temp3);
              squareSetNumber(tempPtr3,decimal);
          }
          
          else if((temp3&temp2) == 0){
            for(m=0;m<9;m++){
            int value = temp3 &(conv<<m);
              if(value != 0){
                int decimal = checkBinaryValue(value);
                squareSetNumber(tempPtr3,decimal);
              }
            }
          }
          
          else{
            for(m=0;m<9;m++){
              int store1 = temp3 & (conv<<m);
              int store2 = temp2 & (conv<<m);
                if(store1 == store2){
                  store3 = store1;
                }else{
                  store1 = 0;
                  store3 = store1;
                }
                int value = store3 &(conv<<m);
                if(value != 0){
                  int decimal = checkBinaryValue(value);
                  squareDelNumber(tempPtr3,decimal);
                  int check = *tempPtr3;

                  if(check == 0){
                    Throw(ERR_EMPTY_SQU);
                  }
                }
              
            }
          } 
          
      }
    }
    
  }

void eliminateBruteForce(int squares[9][9]){
  int dupSquares[9][9];
  int r, c;
  int bitToMask = 0x01;
  int checkForContainTwoNumber;
  int *numberInAddress;
  int *backToDupSquares;
  int numberFromDupSquare;
  int i;
  int getOneFromSquare;
  int numberToChooseInSquare;
  int numberToDelete;
  int getOut;
  int setNumber;
  int *testGet;
  int getFromTest;
  Square sq;
  
  int *test1;
  int test2;
  
  
  sq = selectSquareWithLeastValues(squares);
  
  for(r = 0; r < 9; r++){
    for(c = 0; c < 9; c++){
      duplicateSquares(squares, dupSquares);
    
      if((sq.row == r) && (sq.column == c)){
        numberInAddress = getSquare(squares, actualRow, actualColumn);
        numberToChooseInSquare = *numberInAddress;
        printf("r = %d c = %d numberToChooseInSquare = %d\n", sq.row, sq.column, numberToChooseInSquare);

        for(i = 0; ((getOut != 1) && (i < 9)); i++){  
          getOneFromSquare = numberToChooseInSquare & (bitToMask << i);
          if(getOneFromSquare != 0){
            Try{
              numberToDelete = checkBinaryValue(getOneFromSquare);
              eliminateNumberFromAllPeers(squares, actualRow, actualColumn, numberToDelete);
              testGet = getSquare(squares, actualRow, actualColumn);
              getFromTest = *testGet;
              setNumber = checkBinaryValue(getFromTest);
              getOut = 1;
            }Catch(e){
              printf("ERROR THROW \n");
              backToDupSquares = getSquare(dupSquares, actualRow, actualColumn);
              numberFromDupSquare = *backToDupSquares;
              getOneFromSquare = numberFromDupSquare;
              duplicateSquares(dupSquares, squares);
            }
          }
        }
      }
    }
  }
}


