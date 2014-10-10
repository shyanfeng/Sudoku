#include "unity.h"
#include "Square.h"

void setUp(void){}

void tearDown(void){}

void test_getSquare_should_enter_column_2_row_1_and_return_2(void){
	int column = 2;
	int row = 1;
	int square[9][9];
	int *valuePtr;
	
	square[column-1][row-1] = 2;
	valuePtr = getSquare(&square, column, row);
	
	TEST_ASSERT_EQUAL(2, *valuePtr);
}

void test_getSquare_should_enter_column_6_row_4_and_return_7(void){
	int column = 6;
	int row = 4;
	int square[9][9];
	int *valuePtr;
	
	square[column-1][row-1] = 7;
	valuePtr = getSquare(&square, column, row);
	
	TEST_ASSERT_EQUAL(7, *valuePtr);
}

void test_squareSetNumber_should_enter_column_2_row_1_and_set_3(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 2, 1), 3);
	
	TEST_ASSERT_EQUAL(3, square[1][0]);
}

void test_squareSetNumber_should_enter_column_3_row_8_and_set_4(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 3, 8), 4);
	
	TEST_ASSERT_EQUAL(4, square[2][7]);
}

void test_squareDelNumber_should_enter_column_4_row_2_and_del(void){
	int square[9][9];
	squareDelNumber(getSquare(&square, 4, 2));
	
	TEST_ASSERT_EQUAL(0, square[3][1]);
}

void test_squareDelNumber_should_enter_column_9_row_9_and_del(void){
	int square[9][9];
	squareDelNumber(getSquare(&square, 9, 9));
	
	TEST_ASSERT_EQUAL(0, square[8][8]);
}