#include <stdio.h>
#include "Square.h"


int *getSquare(int (*square)[][9], int column, int row){
	return &((*square)[column-1][row-1]);
} 

void squareSetNumber(int *square,int number){
	*square = number;
}

void squareDelNumber(int *square){
	*square = 0;
}