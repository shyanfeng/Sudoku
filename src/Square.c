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

/*
* Aim: To make 0x1ff to become 0 value in square; 
*
* Input: Square;
*/
void squareSetNumberForZero(int *square){
  (*square) = (*square) & (0x00);
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

/*
* Aim: To initialize the neighbour/peers of Row 
*
* Input: rowPeers[9][9][9]
*/
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

/*
* Aim: To initialize the neighbour/peers of Column 
*
* Input: columnPeers[9][9][9]
*/
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

/*
* Aim: To initialize the neighbour/peers of Box 
*
* Input: boxPeers[9][9][9]
*/
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

/*
* Aim: To check The range of Box 
*      Example(If box stop at 1 then return 0);
*
* Input: index;
* 
* Return: 0,3,6
*/
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

/*
* Aim: To convert Decimal value to Hex Value
*
* Input: value;
* 
* Return: 1,2,3,4,5,6,7,8,9
*/
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

/*
* Aim: To check square contain Two Value 
*
* Input: Square,peers,row,col;
* 
* Return: 1/0
*/
int squareContainTwoNumbers(int square[9][9], int row, int column){
  int getValueFromTemp1;
  getValueFromTemp1 = squareContainNumbers(square, row, column);  

  if(getValueFromTemp1 == 2){
    return 1;
  }else{
    return 0;
  }  
}

/*
* Aim: To check square contain one Value 
*
* Input: Square,peers,row,col;
* 
* Return: 1/0
*/
int squareContainOneNumbers(int square[9][9], int row, int column){
  int getValueFromTemp1;
  getValueFromTemp1 = squareContainNumbers(square, row, column);

  if(getValueFromTemp1 == 1){
    return 1;
  }else{
    return 0;
  }  
}

/*
* Aim: To check square contain how many Value 
*
* Input: Square,peers,row,col;
* 
* Return: getValueFromTemp1
*/
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

/*
* Aim: fix Value1 and check Other square have the same value with Value1 
*
* Input: Square,row,col,val;
*
* Return: 1/0 
*/
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

/*
* Aim: To check all Square is it one Value
*
* Input: Square;
*
* Return: 1/0
*/
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

/*
* Aim: To Call eliminate Child from all peers
*      (Recursive Call to child  
*
* Input: Square,row,col,val;
*/
void eliminateNumberFromAllPeers(int squares[9][9], int row, int column, int value){
  Square *peersRow = rowPeers[row - 1][column - 1];
  Square *peersColumn = columnPeers[row - 1][column - 1];
  Square *peersBox = boxPeers[row - 1][column - 1];

    eliminateNumberFromPeers(squares, peersRow, row, column, value);
    eliminateNumberFromPeers(squares, peersColumn, row, column, value);
    eliminateNumberFromPeers(squares, peersBox, row, column, value);

}

/*
* Aim: To eliminate number from peers  
*      (Recursive to Parent);
* Input: Square,peers,row,col,val;
* Del: val
* Throw:ERR_EMPTY_SQU
*
*/
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
        squareDelNumber(value2, decimalValue);
        int value1 = *value2;
        if(value1 == 0){
          Throw(ERR_EMPTY_SQU);
        }else if(squareContainOneNumbers(squares, getActualRowForPeers, getActualColumnForPeers) == 1){
          int value2 = checkBinaryValue(value1);
          eliminateNumberFromAllPeers(squares, getActualRowForPeers, getActualColumnForPeers, value2);
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

/*
* Aim: To fix the column and checkRow have repeat number  
*
* Input: Square,peers,row,val;
* Del: val if repeated
*/
void forCheckRowNakedSolver(int square[9][9],Square *peers,int j,int temp1){
  int k,m;
  int temp3;
  int conv = 0x01;
  int store3;
  
   for(k=0;k<9;k++){
    int *tempPtr3;
    tempPtr3 = getSquare(square,peers[j].row+1,peers[k].column+1);
    temp3 = *tempPtr3;

      if(temp3 == temp1){
        for(m=0;m<9;m++){
          int value = temp3 &(conv<<m);
          if(value != 0){
            int decimal = checkBinaryValue(value);
            squareSetNumber(tempPtr3,decimal);
          }
        }
      }
      
      else{
          if(squareContainOneNumbers(square,peers[j].row+1,peers[k].column+1) == 1){
              int decimal = checkBinaryValue(temp3);
              squareSetNumber(tempPtr3,decimal);
          }
          
          else if((temp3&temp1) == 0){
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
              int store2 = temp1 & (conv<<m);
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

/*
* Aim: To fix the row and checkColumn have repeat number  
*
* Input: Square,peers,col,val;
* Del: val if repeated
*/
void forCheckColumnNakedSolver(int square[9][9],Square *peers,int j,int temp1){
  int k,m;
  int temp3;
  int conv = 0x01;
  int store3;
  
   for(k=0;k<9;k++){
    int *tempPtr3;
    tempPtr3 = getSquare(square,peers[k].row+1,peers[j].column+1);
    temp3 = *tempPtr3;

      if(temp3 == temp1){
        for(m=0;m<9;m++){
          int value = temp3 &(conv<<m);
          if(value != 0){
            int decimal = checkBinaryValue(value);
            squareSetNumber(tempPtr3,decimal);
          }
        }
      }
      
      else{
          if(squareContainOneNumbers(square,peers[k].row+1,peers[j].column+1) == 1){
              int decimal = checkBinaryValue(temp3);
              squareSetNumber(tempPtr3,decimal);
          }
          
          else if((temp3&temp1) == 0){
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
              int store2 = temp1 & (conv<<m);
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

/*
* Aim: checkBox have repeat number  
*
* Input: Square,peers,val;
* Del: val if repeated
*/ 
void forCheckBoxNakedSolver(int square[9][9],Square *peers,int temp1){
  int k,m;
  int temp3;
  int conv = 0x01;
  int store3;
  
   for(k=0;k<9;k++){
    int *tempPtr3;
    tempPtr3 = getSquare(square,peers[k].row+1,peers[k].column+1);
    temp3 = *tempPtr3;

      if(temp3 == temp1){
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
          
          else if((temp3&temp1) == 0){
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
              int store2 = temp1 & (conv<<m);
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

/*
* Aim: To call eliminateNakedPairInPeers for row column and box  
*
* Input: Square
* Output: eliminateBruteForce / dumpSquare
*/ 
void eliminateNakedPair(int square[9][9]){
  int r,c;
  int temp;
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
  
  if(isSudokuSolved(square) == 0){
    eliminateBruteForce(square);
  }else{
    // dumpSquare(square);
  } 
}

/*
* Aim: To match and check which is same value with initial
*      Del other same value
*
* Input: Square and peers
*
* Del: peers Value if repeat
*/
void eliminateNakedPairInPeers(int square[9][9],Square *peers){
  int i,j,m,n;
  int k = 0;
  int *tempPtr,*tempPtr1,*tempPtr4;
  int temp,temp1,temp2,temp3;
  int conv = 0x01;
  int storeVal;
  int store3;

  for(i=0;i<9;i++){
     for(j=i+1;j<9;j++){
    if(squareContainTwoNumbers(square,peers[i].row+1,peers[i].column+1) == 1 && squareContainTwoNumbers(square,peers[j].row+1,peers[j].column+1) == 1 ){   
        tempPtr = getSquare(square,peers[i].row+1,peers[i].column+1);
        temp = *tempPtr;
        tempPtr1 = getSquare(square,peers[j].row+1,peers[j].column+1);
        temp1 = *tempPtr1;
        if(temp == temp1){
          if(peers[i].row == peers[j].row){
            forCheckRowNakedSolver(square,peers,j,temp1);
          }else if(peers[i].column == peers[j].column){
            forCheckColumnNakedSolver(square,peers,j,temp1);
          }else{
            forCheckBoxNakedSolver(square,peers,temp1);
          }
        }
    }
    }
  }
}
 
/*
* Aim: To call eliminateNakedPairInPeers for row column and box  
*
* Input: Square
* Output: eliminateBruteForce / dumpSquare
*/ 
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
  
  if(isSudokuSolved(square) == 0){
    eliminateBruteForce(square);
  }else{
    // dumpSquare(square);
  }  
}
 
/*
* Aim: To match and check which is same value with initial
*      Del other same value
*
* Input: Square and peers
*
* Del: peers Value if repeat
*/ 
void eliminateNakedTriplesInPeers(int square[9][9],Square *peers){
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
    if(squareContainNumbers(square,peers[i].row+1,peers[i].column+1) == 3 && squareContainNumbers(square,peers[j].row+1,peers[j].column+1) == 3){   
        tempPtr = getSquare(square,peers[i].row+1,peers[i].column+1);
        temp = *tempPtr;
        tempPtr1 = getSquare(square,peers[j].row+1,peers[j].column+1);
        temp1 = *tempPtr1;
        if(temp == temp1){
          if(peers[i].row == peers[j].row){
            forCheckRowNakedSolver(square,peers,j,temp1);
          }else if(peers[i].column == peers[j].column){
            forCheckColumnNakedSolver(square,peers,j,temp1);
          }else{
            forCheckBoxNakedSolver(square,peers,temp1);
          }    
        }
    }
    }
  }  
}

/*
* Aim: To call eliminateNakedPairInPeers for row column and box  
*
* Input: Square
* Output: eliminateBruteForce / dumpSquare
*/
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
  
  if(isSudokuSolved(square) == 0){
    eliminateBruteForce(square);
  }else{
    // dumpSquare(square);
  }
}

/*
* Aim: To match and check which is same value with initial
*      Del other same value
*
* Input: Square and peers
*
* Del: peers Value if repeat
*/
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
          if(peers[i].row == peers[j].row){
            forCheckRowNakedSolver(square,peers,j,temp1);
          }else if(peers[i].column == peers[j].column){
            forCheckColumnNakedSolver(square,peers,j,temp1);
          }else{
            forCheckBoxNakedSolver(square,peers,temp1);
          } 
        }
    }
    }
  }
}
  
void eliminateBruteForce(int squares[9][9]){

  int dupSquares[9][9];

  int r, c, i;
  int bitToMask = 0x01;
  int checkForContainTwoNumber;
  int *numberInAddress;
  int *backToDupSquares;
  int numberFromDupSquare;
  int getOneFromSquare;
  int numberToChooseInSquare;
  int numberToDelete;
  int getOut;
  int setNumber;
  int *testGet;
  int getFromTest;

  Square sq;
  

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
              if(isSudokuSolved(squares) == 0){
                eliminateNakedPair(squares);
              }else{
                // dumpSquare(squares);
                getOut = 1;
              }

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

/*
* Aim: To print Out final Value (when all square contain one value) 
*
* Input: Square
*/
void dumpSquare(int square[9][9]){
  int r,c,i,j;
  int *printPtr;
  int printDecimal;
   
  printf("\n");
  printf("+-+-+-+-+-+-+-+-+-+ \n");
  for(r=0;r<9;r++){
    for(c=0;c<10;c++){
      printPtr = getSquare(square, actualRow, actualColumn);
      printDecimal = *printPtr;
      int printHex = checkBinaryValue(printDecimal);
      for(i = 0 ; i < 1 ; i++){
        printf("|");
      }
      if(c == 9){
        printf("\n");
        printf("+-+-+-+-+-+-+-+-+-+");
        printf("\n");
      }else{
        printf("%d",printHex);
      }
    }
  }

}

/*
* Aim: To combine and call All Eliminate techniques  
*
* Input: Square
*/
void combineAllEliminate(int square[9][9]){
  eliminateNakedPair(square);
  eliminateNakedTriples(square);
  eliminateNakedQuad(square);
}

void searchPosibilityValueOfEmptySquare(int square[9][9]){
  int r,c;
  for(r=0;r<9;r++){
    for(c=0;c<9;c++){
        Square *peersRow = rowPeers[r][c];
        // Square *peersColumn = columnPeers[r][c];        
        // Square *peersBox = boxPeers[r][c];
        searchPosibilityValueOfEmptySquareInPeers(square,peersRow);
        // searchPosibilityValueOfEmptySquareInPeers(square,peersColumn);
        // searchPosibilityValueOfEmptySquareInPeers(square,peersBox);
    }
  }
}

void searchPosibilityValueOfEmptySquareInPeers(int square[9][9],Square *peers){
  int r,c,i,j,m;
  int *checkZeroPtr,*checkValuePtr;
  int checkZero,checkValue;
  int conv = 0x01;
 for(r=0;r<9;r++){
       checkZeroPtr = getSquare(square,peers[r].row+1,peers[r].column+1);
       checkZero = *checkZeroPtr;
      if(checkZero == 511){
        for(c=0;c<9;c++){
          checkValuePtr = getSquare(square,peers[c].row+1,peers[c].column+1);
          checkValue = *checkValuePtr;
          if( checkValue != 0 && checkValue != 511){
            checkZero = checkZero & checkValue;
            if(checkZero != 0){
              squareSetNumberForZero(checkZeroPtr);
              for(m=0;m<9;m++){
                int value = checkZero & (conv << m);
                if(value != 0){
                    int hexValue = checkBinaryValue(value);
                    squareSetNumber(checkZeroPtr,hexValue);
                }
              }       
            }
          }
        }
   

      }
  }
  
}







