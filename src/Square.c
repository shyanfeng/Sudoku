#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"


int *getSquare(int (*square)[][9], int column, int row){
	return &((*square)[column-1][row-1]);
} 

void squareSetNumber(int *square,int number){
	*square = number;
}

void squareDelNumber(int *square){
	*square = 0;
}

int eliminateNeighbouringSquaresOf(int *square, int number){
    int i, j;
    int e;
    
    for(i = 0; i < 9; i++){
        if(*square == number){
            Throw(e);
        }
    }
}