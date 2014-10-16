#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"


int *getSquare(int (*square)[9][9], int column, int row){
	return &((*square)[column-1][row-1]);
} 

void squareSetNumber(int *square, int number){
	*square = number;
}

void squareDelNumber(int *square, int number){
	number = 0;
	*square = number;
}

void eliminateNeighbouringSquaresOf(int (*square)[9][9], int number){
    /*int i, j;

    for(i = 1; i < 9; i++){
        if((*square)[i][9] == number){
			
			(*square)[i][9] = 0;
        }
    }*/
	
	
}