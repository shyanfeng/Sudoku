#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"

int *getSquare(int (*square)[9][9], int row, int column){
	return &((*square)[row-1][column-1]);
} 

void squareSetNumber(int *square, int number){
  (*square) = (*square) | (C(number));
}

void squareDelNumber(int *square, int number){
  (*square) = (*square) & (~(1 <<(number - 1)));
}

void eliminateNeighbouringSquaresOf(int (*square)[9][9], int number){
    /*int i, j;

    for(i = 1; i < 9; i++){
        if((*square)[i][9] == number){
			
			(*square)[i][9] = 0;
        }
    }*/
	
	
}