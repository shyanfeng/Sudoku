#include "unity.h"
#include "Square.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_getSquare_should_enter_column_2_row_1_and_return_2(void){
	int column = 2;
	int row = 1;
	int square[9][9];
	int *valuePtr;
	
	square[row-1][column-1] = 2;
	valuePtr = getSquare(&square, row, column);
	
	TEST_ASSERT_EQUAL(2, *valuePtr);
}

void test_getSquare_should_enter_column_6_row_4_and_return_7(void){
	int column = 6;
	int row = 4;
	int square[9][9];
	int *valuePtr;
	
	square[row-1][column-1] = 7;
	valuePtr = getSquare(&square, row, column);
	
	TEST_ASSERT_EQUAL(7, *valuePtr);
}

void test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 2, 1), 3);
    // 0 0000 0100
	TEST_ASSERT_EQUAL(4, square[1][0]);
}

void test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 3, 8), 4);
	// 0 0000 1000
	TEST_ASSERT_EQUAL(8, square[2][7]);
}

void test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 9, 9), 2);
	// 0 0000 0010
	TEST_ASSERT_EQUAL(2, square[8][8]);
}

void test_squareDelNumber_should_enter_column_4_row_2_and_del(void){
    int square[9][9];
    squareSetNumber(getSquare(&square, 4, 2), 5);
    // 0 0001 0000
    TEST_ASSERT_EQUAL(16, square[3][1]);
	squareDelNumber(getSquare(&square, 4, 2), 5);
	TEST_ASSERT_EQUAL(0, square[3][1]);
}

void test_squareDelNumber_should_enter_column_9_row_9_and_del(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 9, 9), 6);
    // 0 0010 0000
	TEST_ASSERT_EQUAL(32, square[8][8]);
	squareDelNumber(getSquare(&square, 9, 9), 6);
	TEST_ASSERT_EQUAL(0, square[8][8]);
}

void test_squareDelNumber_should_enter_column_5_row_1_and_del(void){
	int square[9][9];
	squareSetNumber(getSquare(&square, 5, 1), 2);
    // 0 0000 0010
	TEST_ASSERT_EQUAL(2, square[4][0]);
	squareDelNumber(getSquare(&square, 5, 1), 2);
	TEST_ASSERT_EQUAL(0, square[4][0]);
}

/*void test_eliminateNeighbouringSquaresOf_should_throw_error_for_row(void){
	int square[9][9] = {{C(1), C(0), C(0), C(0), C(0), C(0), C(0), C(0),C(0)}, // 1
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 2
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 3
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 4
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 5
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 6
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 7
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 8
                        {1, 3, 3, 3, 3, 3, 3, 3, 3}, // 9
                        };
		

		
		eliminateNeighbouringSquaresOf((*square)[1][], number)
    
    
        value = squareDelNumber(getSquare(&square, 1, 1), 1);

	
}*/









