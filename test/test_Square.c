#include "unity.h"
#include "Square.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_getSquare_should_enter_column_2_row_1_and_return_2(void){
	int column = 2;
	int row = 1;
	int square[9][9];
	int *valuePtr;
	
	square[row-1][column-1] = 2;
	valuePtr = getSquare(square, row, column);
	
	TEST_ASSERT_EQUAL(2, *valuePtr);
}

void test_getSquare_should_enter_column_6_row_4_and_return_7(void){
	int column = 6;
	int row = 4;
	int square[9][9];
	int *valuePtr;
	
	square[row-1][column-1] = 7;
	valuePtr = getSquare(square, row, column);
	
	TEST_ASSERT_EQUAL(7, *valuePtr);
}

void test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3_2_1_4(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 2, 1), 3);
  squareSetNumber(getSquare(square, 2, 1), 2);
  squareSetNumber(getSquare(square, 2, 1), 1);
  squareSetNumber(getSquare(square, 2, 1), 4);
  // 0 0000 1111
	TEST_ASSERT_EQUAL(15, square[1][0]);
}

void test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4_2_6(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 3, 8), 4);
	squareSetNumber(getSquare(square, 3, 8), 2);
	squareSetNumber(getSquare(square, 3, 8), 6);
	// 0 0010 1010
	TEST_ASSERT_EQUAL(42, square[2][7]);
}

void test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2_7_8(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 9, 9), 2);
	squareSetNumber(getSquare(square, 9, 9), 7);
	squareSetNumber(getSquare(square, 9, 9), 8);
	// 0 1100 0010
	TEST_ASSERT_EQUAL(194, square[8][8]);
}

void test_squareDelNumber_should_enter_column_4_row_2_and_del_bit_5(void){
  int square[9][9];
  clearSquares(square);
  
  squareSetNumber(getSquare(square, 4, 2), 5);
  squareSetNumber(getSquare(square, 4, 2), 8);
  squareSetNumber(getSquare(square, 4, 2), 1);
  // 0 1001 0001
  TEST_ASSERT_EQUAL(145, square[3][1]);
  
	squareDelNumber(getSquare(square, 4, 2), 5);
  // 0 1000 0001
	TEST_ASSERT_EQUAL(129, square[3][1]);
}

void test_squareDelNumber_should_enter_column_9_row_9_and_del_bit_6(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 9, 9), 6);
	squareSetNumber(getSquare(square, 9, 9), 2);
	squareSetNumber(getSquare(square, 9, 9), 7);
  // 0 0110 0010
	TEST_ASSERT_EQUAL(98, square[8][8]);
  
	squareDelNumber(getSquare(square, 9, 9), 6);
  // 0 0100 0010
	TEST_ASSERT_EQUAL(66, square[8][8]);
}

void test_squareDelNumber_should_enter_column_5_row_1_and_del_bit_2_4(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 5, 1), 2);
	squareSetNumber(getSquare(square, 5, 1), 4);
	squareSetNumber(getSquare(square, 5, 1), 7);
  // 0 0100 1010
	TEST_ASSERT_EQUAL(74, square[4][0]);
  
	squareDelNumber(getSquare(square, 5, 1), 2);
	squareDelNumber(getSquare(square, 5, 1), 4);
  // 0 0100 0000
	TEST_ASSERT_EQUAL(64, square[4][0]);
}

void test_removeOthersExcept_should_enter_column_4_row_2_and_remove_all_except_4(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 4, 2), 2);
	squareSetNumber(getSquare(square, 4, 2), 4);
	squareSetNumber(getSquare(square, 4, 2), 7);
  // 0 0100 1010
	TEST_ASSERT_EQUAL(74, square[3][1]);
  
	removeOthersExcept(getSquare(square, 4, 2), 2);
  // 0 0000 0010
	TEST_ASSERT_EQUAL(2, square[3][1]);
}

void test_removeOthersExcept_should_enter_column_7_row_3_and_remove_all_except_4(void){
	int square[9][9];
  clearSquares(square);
  
	squareSetNumber(getSquare(square, 7, 2), 8);
	squareSetNumber(getSquare(square, 7, 2), 6);
	squareSetNumber(getSquare(square, 7, 2), 3);
  // 0 1010 0100
	TEST_ASSERT_EQUAL(164, square[6][1]);
  
	removeOthersExcept(getSquare(square, 7, 2), 6);
  // 0 0010 0000
	TEST_ASSERT_EQUAL(32, square[6][1]);
}

void test_isSquareContain_should_return_1_for_number_match_square(void){
  int square[9][9];
  clearSquares(square);
  
  int value;
  
  squareSetNumber(getSquare(square, 4, 6), 4);
  // 0 0000 1000
  TEST_ASSERT_EQUAL(8, square[3][5]);
  
  value = isSquareContain(getSquare(square, 4, 6), 4);
  TEST_ASSERT_EQUAL(1, value);
}

void test_initRowPeers(void){
  
  initRowPeers(rowPeers);
  
  TEST_ASSERT_EQUAL(0, rowPeers[2][2][0].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][0].column);
  TEST_ASSERT_EQUAL(1, rowPeers[2][2][1].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][1].column);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][2].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][2].column);
  TEST_ASSERT_EQUAL(3, rowPeers[2][2][3].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][3].column);
  TEST_ASSERT_EQUAL(4, rowPeers[2][2][4].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][4].column);
  TEST_ASSERT_EQUAL(5, rowPeers[2][2][5].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][5].column);
  TEST_ASSERT_EQUAL(6, rowPeers[2][2][6].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][6].column);
  TEST_ASSERT_EQUAL(7, rowPeers[2][2][7].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][7].column);
  TEST_ASSERT_EQUAL(8, rowPeers[2][2][8].row);
  TEST_ASSERT_EQUAL(2, rowPeers[2][2][8].column);
}

void test_initColPeers(void){

  initColPeers(columnPeers);
  
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][0].row);
  TEST_ASSERT_EQUAL(0, columnPeers[2][2][0].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][1].row);
  TEST_ASSERT_EQUAL(1, columnPeers[2][2][1].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][2].row);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][2].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][3].row);
  TEST_ASSERT_EQUAL(3, columnPeers[2][2][3].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][4].row);
  TEST_ASSERT_EQUAL(4, columnPeers[2][2][4].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][5].row);
  TEST_ASSERT_EQUAL(5, columnPeers[2][2][5].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][6].row);
  TEST_ASSERT_EQUAL(6, columnPeers[2][2][6].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][7].row);
  TEST_ASSERT_EQUAL(7, columnPeers[2][2][7].column);
  TEST_ASSERT_EQUAL(2, columnPeers[2][2][8].row);
  TEST_ASSERT_EQUAL(8, columnPeers[2][2][8].column);
}

void test_getBeginningIndex(void){
  
  TEST_ASSERT_EQUAL(0, getBeginningIndex(1));
  TEST_ASSERT_EQUAL(0, getBeginningIndex(0));
  TEST_ASSERT_EQUAL(0, getBeginningIndex(2));
  TEST_ASSERT_EQUAL(3, getBeginningIndex(5));
  TEST_ASSERT_EQUAL(3, getBeginningIndex(4));
  TEST_ASSERT_EQUAL(3, getBeginningIndex(3));
  TEST_ASSERT_EQUAL(6, getBeginningIndex(8));
  TEST_ASSERT_EQUAL(6, getBeginningIndex(7));
  TEST_ASSERT_EQUAL(6, getBeginningIndex(6)); 
}

void test_initBoxPeers(void){
 initBoxPeers(boxPeers);

	TEST_ASSERT_EQUAL(0, boxPeers[2][2][0].row);
  TEST_ASSERT_EQUAL(0, boxPeers[2][2][0].column); 
  TEST_ASSERT_EQUAL(0, boxPeers[2][2][1].row);
  TEST_ASSERT_EQUAL(1, boxPeers[2][2][1].column); 
  TEST_ASSERT_EQUAL(0, boxPeers[2][2][2].row);
  TEST_ASSERT_EQUAL(2, boxPeers[2][2][2].column);
  TEST_ASSERT_EQUAL(1, boxPeers[2][2][3].row);
  TEST_ASSERT_EQUAL(0, boxPeers[2][2][3].column);
  TEST_ASSERT_EQUAL(1, boxPeers[2][2][4].row);
  TEST_ASSERT_EQUAL(1, boxPeers[2][2][4].column);
  TEST_ASSERT_EQUAL(1, boxPeers[2][2][5].row);
  TEST_ASSERT_EQUAL(2, boxPeers[2][2][5].column);
  TEST_ASSERT_EQUAL(2, boxPeers[2][2][6].row);
  TEST_ASSERT_EQUAL(0, boxPeers[2][2][6].column);
  TEST_ASSERT_EQUAL(2, boxPeers[2][2][7].row);
  TEST_ASSERT_EQUAL(1, boxPeers[2][2][7].column);
  TEST_ASSERT_EQUAL(2, boxPeers[2][2][8].row);
  TEST_ASSERT_EQUAL(2, boxPeers[2][2][8].column);
}

void test_initBoxPeers_1(void){
 initBoxPeers(boxPeers);

	TEST_ASSERT_EQUAL(3, boxPeers[4][2][0].row);
  TEST_ASSERT_EQUAL(0, boxPeers[4][2][0].column); 
  TEST_ASSERT_EQUAL(3, boxPeers[4][2][1].row);
  TEST_ASSERT_EQUAL(1, boxPeers[4][2][1].column); 
  TEST_ASSERT_EQUAL(3, boxPeers[4][2][2].row);
  TEST_ASSERT_EQUAL(2, boxPeers[4][2][2].column);
  TEST_ASSERT_EQUAL(4, boxPeers[4][2][3].row);
  TEST_ASSERT_EQUAL(0, boxPeers[4][2][3].column);
  TEST_ASSERT_EQUAL(4, boxPeers[4][2][4].row);
  TEST_ASSERT_EQUAL(1, boxPeers[4][2][4].column);
  TEST_ASSERT_EQUAL(4, boxPeers[4][2][5].row);
  TEST_ASSERT_EQUAL(2, boxPeers[4][2][5].column);
  TEST_ASSERT_EQUAL(5, boxPeers[4][2][6].row);
  TEST_ASSERT_EQUAL(0, boxPeers[4][2][6].column);
  TEST_ASSERT_EQUAL(5, boxPeers[4][2][7].row);
  TEST_ASSERT_EQUAL(1, boxPeers[4][2][7].column);
  TEST_ASSERT_EQUAL(5, boxPeers[4][2][8].row);
  TEST_ASSERT_EQUAL(2, boxPeers[4][2][8].column);
}

void test_squareHas_has_same_number_return_1(void){
  int square[9][9] = {{C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(8)|C(1), C(1), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                     };

  int replyValue = squareHas(square,2,2,8);
  TEST_ASSERT_EQUAL(1,replyValue);
}

void test_squareHas_does_not_have_same_number_return_0(void){
  int square[9][9] = {{C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)},
                     };

  int replyValue = squareHas(square,2,2,3);
  TEST_ASSERT_EQUAL(0,replyValue);
}

void test_squareContainOneNumbers_has_more_than_1_number_return_0(void){
  int square[9][9] = {{C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(8)|C(2), C(1), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                     };

  int replyValue = squareContainOneNumbers(square,2,2);
  TEST_ASSERT_EQUAL(0,replyValue);
}

void test_squareContainOneNumbers_has_one_value_return_1(void){
  int square[9][9] = {{C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(8), C(1), C(0), C(7), C(0), C(0), C(0),C(0)},
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                      {C(3), C(0), C(0), C(0), C(7), C(0), C(0), C(0),C(0)}, 
                     };
                     
  int Value = squareContainOneNumbers(square,2,2);
  TEST_ASSERT_EQUAL(1,Value);
}

void test_checkBinaryValue_return_number(void){
  int returnValue;
  returnValue = checkBinaryValue(1);
  TEST_ASSERT_EQUAL(1,returnValue);
  
  returnValue = checkBinaryValue(2);
  TEST_ASSERT_EQUAL(2,returnValue);
  
  returnValue = checkBinaryValue(4);
  TEST_ASSERT_EQUAL(3,returnValue);
  
  returnValue = checkBinaryValue(8);
  TEST_ASSERT_EQUAL(4,returnValue);
  
  returnValue = checkBinaryValue(16);
  TEST_ASSERT_EQUAL(5,returnValue);
  
  returnValue = checkBinaryValue(32);
  TEST_ASSERT_EQUAL(6,returnValue);
  
  returnValue = checkBinaryValue(64);
  TEST_ASSERT_EQUAL(7,returnValue);
  
  returnValue = checkBinaryValue(128);
  TEST_ASSERT_EQUAL(8,returnValue);
  
  returnValue = checkBinaryValue(256);
  TEST_ASSERT_EQUAL(9,returnValue);
}

void test_eliminateNumberFromAllPeers_with_2_recursive(void){
                       // 0    1                2           3     4           5               6     7    8
  int square[9][9] = {{C(3), C(2)|C(4)|C(3),  C(6),       C(1), C(1),       C(8),           C(9), C(2),C(1)}, //0 
                      {C(2), C(6)|C(4),       C(2)|C(3),  C(1), C(8)|C(4),  C(5)|C(3)|C(1), C(6), C(7),C(3)}, //1
                      {C(1), C(9)|C(4),       C(3),       C(3), C(2),       C(1),           C(1), C(1),C(1)}, //2
                      
                      {C(1), C(3),            C(1),       C(1), C(2),       C(1),           C(1), C(1),C(1)}, //3
                      {C(1), C(6),            C(1),       C(1), C(2),       C(1),           C(1), C(1),C(1)}, //4
                      {C(1), C(9)|C(5)|C(2),  C(1),       C(1), C(2),       C(1),           C(1), C(1),C(1)}, //5
                      
                      {C(1), C(3),            C(1),       C(1), C(2),       C(1),           C(1), C(1),C(1)}, //6
                      {C(1), C(1),            C(1),       C(1), C(2),       C(1),           C(1), C(1),C(1)}, //7
                      {C(1), C(2),            C(1),       C(1), C(2),       C(1),           C(1), C(1),C(1)}, //8
                     };  
    
  ErrorCode e;

  Try{
    eliminateNumberFromAllPeers(square, 2, 2, 6);
  }Catch(e){
  TEST_ASSERT_EQUAL(ERR_EMPTY_SQU, e);
  //row
  TEST_ASSERT_EQUAL(6, square[0][1]);
  TEST_ASSERT_EQUAL(8, square[1][1]);
  TEST_ASSERT_EQUAL(256, square[2][1]);
  TEST_ASSERT_EQUAL(4, square[3][1]);
  TEST_ASSERT_EQUAL(32, square[4][1]);
  TEST_ASSERT_EQUAL(18, square[5][1]);
  TEST_ASSERT_EQUAL(4, square[6][1]);
  TEST_ASSERT_EQUAL(1, square[7][1]);
  TEST_ASSERT_EQUAL(2, square[8][1]);
  
  //column
  TEST_ASSERT_EQUAL(2, square[1][0]);
  TEST_ASSERT_EQUAL(8, square[1][1]);
  TEST_ASSERT_EQUAL(6, square[1][2]);
  TEST_ASSERT_EQUAL(1, square[1][3]);
  TEST_ASSERT_EQUAL(128, square[1][4]);
  TEST_ASSERT_EQUAL(21, square[1][5]);
  TEST_ASSERT_EQUAL(32, square[1][6]);
  TEST_ASSERT_EQUAL(64, square[1][7]);
  TEST_ASSERT_EQUAL(4, square[1][8]);
  
  //box
  TEST_ASSERT_EQUAL(4, square[0][0]);
  TEST_ASSERT_EQUAL(6, square[0][1]);
  TEST_ASSERT_EQUAL(32, square[0][2]);
  TEST_ASSERT_EQUAL(2, square[1][0]);
  TEST_ASSERT_EQUAL(8, square[1][1]);
  TEST_ASSERT_EQUAL(6, square[1][2]);
  TEST_ASSERT_EQUAL(1, square[2][0]);
  TEST_ASSERT_EQUAL(256, square[2][1]);
  TEST_ASSERT_EQUAL(4, square[2][2]);
  }
}

void test_eliminateNumberFromAllPeers_with_3_recursive(void){
                       // 0         1                2               3     4           5           6      7    8
  int square[9][9] = {{C(2),      C(2)|C(4)|C(3),  C(7),           C(1), C(1),       C(1),       C(1), C(1), C(1)}, //0 
                      {C(9),      C(8)|C(4)|C(2),  C(2)|C(5)|C(6), C(1), C(1),       C(1),       C(1), C(1), C(1)}, //1
                      {C(1),      C(9)|C(4),       C(3)|C(5)|C(8), C(3), C(1),       C(1),       C(1), C(1), C(1)}, //2
                      
                      {C(1),      C(6),            C(6)|C(4),      C(1), C(1),       C(1),       C(1), C(1), C(1)}, //3
                      {C(5)|C(3), C(6),            C(8)|C(2),      C(1), C(1),       C(1),       C(1), C(1), C(1)}, //4
                      {C(1),      C(9)|C(3),       C(2)|C(3),      C(1), C(1),       C(1),       C(1), C(1), C(1)}, //5 
                      
                      {C(1),      C(1),            C(1)|C(2)|C(7), C(1), C(1),       C(1),       C(1), C(1), C(1)}, //6
                      {C(1),      C(1),            C(1)|C(4),      C(1), C(1),       C(1),       C(1), C(1), C(1)}, //7
                      {C(1),      C(2),            C(1),           C(1), C(1),       C(1),       C(1), C(1), C(1)}, //8
                     };  
    
  int value;
  eliminateNumberFromAllPeers(square, 6, 3, 2);
  //row
  TEST_ASSERT_EQUAL(64, square[0][2]);
  TEST_ASSERT_EQUAL(50, square[1][2]);
  TEST_ASSERT_EQUAL(144, square[2][2]);
  TEST_ASSERT_EQUAL(40, square[3][2]);
  TEST_ASSERT_EQUAL(130, square[4][2]);
  TEST_ASSERT_EQUAL(4, square[5][2]);
  TEST_ASSERT_EQUAL(67, square[6][2]);
  TEST_ASSERT_EQUAL(9, square[7][2]);
  TEST_ASSERT_EQUAL(1, square[8][2]);
  
  //column
  TEST_ASSERT_EQUAL(1, square[5][0]);
  TEST_ASSERT_EQUAL(256, square[5][1]);
  TEST_ASSERT_EQUAL(4, square[5][2]);
  TEST_ASSERT_EQUAL(1, square[5][3]);
  TEST_ASSERT_EQUAL(1, square[5][4]);
  TEST_ASSERT_EQUAL(1, square[5][5]);
  TEST_ASSERT_EQUAL(1, square[5][6]);
  TEST_ASSERT_EQUAL(1, square[5][7]);
  TEST_ASSERT_EQUAL(1, square[5][8]);
  
  //box
  TEST_ASSERT_EQUAL(1, square[3][0]);
  TEST_ASSERT_EQUAL(32, square[3][1]);
  TEST_ASSERT_EQUAL(40, square[3][2]);
  TEST_ASSERT_EQUAL(16, square[4][0]);
  TEST_ASSERT_EQUAL(32, square[4][1]);
  TEST_ASSERT_EQUAL(130, square[4][2]);
  TEST_ASSERT_EQUAL(1, square[5][0]);
  TEST_ASSERT_EQUAL(256, square[5][1]);
  TEST_ASSERT_EQUAL(4, square[5][2]);
}

void test_eliminateNumberFromAllPeers_for_checking_row_0_column_1(void){
  int square[9][9] = {{C(3),     	    C(7)|C(8),      C(9),           C(8), C(2), C(1), C(4), C(5), C(6)}, 
                      {C(5), 		      C(4),           C(8),           C(9), C(3), C(6), C(7), C(2), C(1)},
                      {C(2),          C(6),           C(1),           C(4), C(5), C(7), C(3), C(9), C(8)}, 
                      {C(1),          C(8)|C(7),      C(5),           C(3), C(6), C(9), C(2), C(4), C(7)},  
                      {C(9),          C(2),           C(4),           C(1), C(7), C(5), C(8), C(6), C(3)},  
                      {C(6),          C(3),           C(7),           C(2), C(8), C(4), C(9), C(1), C(5)},  
                      {C(4),          C(9),           C(3),           C(5), C(1), C(8), C(6), C(7), C(2)},  
                      {C(8),          C(5),           C(6),           C(7), C(9), C(2), C(1), C(3), C(4)},  
                      {C(7),          C(1),           C(2),           C(6), C(4), C(3), C(5), C(8), C(9)}, 
                     };
  ErrorCode e;
  
  Try{
    eliminateNumberFromAllPeers(square,1,2,7);
  }Catch(e)
    TEST_ASSERT_EQUAL(ERR_EMPTY_SQU, e);
}

void test_duplicateSquares(void){
                       // 0    1                2           3         4           5               6      7    8
  int square[9][9] = {{C(3), C(2)|C(4)|C(3),  C(6),       C(1),      C(1),       C(8),           C(9), C(2),C(1)}, //0 
                      {C(2), C(6)|C(4),       C(2)|C(3),  C(1),      C(8)|C(4),  C(5)|C(3)|C(1), C(6), C(7),C(3)}, //1
                      {C(1), C(9)|C(4),       C(3),       C(3),      C(2),       C(1),           C(1), C(1),C(1)}, //2
                      
                      {C(1), C(3),            C(1),       C(1),      C(4),       C(1),           C(1), C(1),C(1)}, //3
                      {C(7), C(6),            C(1),       C(1),      C(5),       C(1),           C(1), C(1),C(1)}, //4
                      {C(8), C(9)|C(5)|C(2),  C(1),       C(5)|C(3), C(6),       C(1),           C(1), C(1),C(1)}, //5
                      
                      {C(1), C(3),            C(1),       C(1),      C(2)|C(5),  C(1),           C(1), C(1),C(1)}, //6
                      {C(9), C(1),            C(1),       C(1),      C(2)|C(7),  C(1),           C(1), C(1),C(1)}, //7
                      {C(1), C(2),            C(1),       C(1),      C(3),       C(1),           C(1), C(1),C(1)}, //8
                     };  
  
  int dupSquares[9][9];
  duplicateSquares(square, dupSquares);
  
  TEST_ASSERT_EQUAL(4, dupSquares[0][0]);
  TEST_ASSERT_EQUAL(14, dupSquares[0][1]);
  TEST_ASSERT_EQUAL(32, dupSquares[0][2]);
  TEST_ASSERT_EQUAL(1, dupSquares[0][3]);
  TEST_ASSERT_EQUAL(1, dupSquares[0][4]);
  TEST_ASSERT_EQUAL(128, dupSquares[0][5]);
  TEST_ASSERT_EQUAL(256, dupSquares[0][6]);
  TEST_ASSERT_EQUAL(2, dupSquares[0][7]);
  TEST_ASSERT_EQUAL(1, dupSquares[0][8]);
  
  TEST_ASSERT_EQUAL(4, dupSquares[0][0]);
  TEST_ASSERT_EQUAL(2, dupSquares[1][0]);
  TEST_ASSERT_EQUAL(1, dupSquares[2][0]);
  TEST_ASSERT_EQUAL(1, dupSquares[3][0]);
  TEST_ASSERT_EQUAL(64, dupSquares[4][0]);
  TEST_ASSERT_EQUAL(128, dupSquares[5][0]);
  TEST_ASSERT_EQUAL(1, dupSquares[6][0]);
  TEST_ASSERT_EQUAL(256, dupSquares[7][0]);
  TEST_ASSERT_EQUAL(1, dupSquares[8][0]);
  
  TEST_ASSERT_EQUAL(1, dupSquares[0][4]);
  TEST_ASSERT_EQUAL(136, dupSquares[1][4]);
  TEST_ASSERT_EQUAL(2, dupSquares[2][4]);
  TEST_ASSERT_EQUAL(8, dupSquares[3][4]);
  TEST_ASSERT_EQUAL(16, dupSquares[4][4]);
  TEST_ASSERT_EQUAL(32, dupSquares[5][4]);
  TEST_ASSERT_EQUAL(18, dupSquares[6][4]);
  TEST_ASSERT_EQUAL(66, dupSquares[7][4]);
  TEST_ASSERT_EQUAL(4, dupSquares[8][4]);
}

void test_isSudokuSolve_return_1_all_square_contain_one_number(void){
  int square[9][9] = {{C(3), C(2), C(4), C(3), C(2), C(1), C(5), C(3),C(1)}, 
                      {C(3), C(8), C(1), C(3), C(7), C(6), C(4), C(6),C(5)},
                      {C(3), C(2), C(5), C(3), C(7), C(6), C(4), C(3),C(1)}, 
                      {C(3), C(3), C(1), C(3), C(7), C(6), C(4), C(1),C(6)}, 
                      {C(3), C(1), C(7), C(3), C(7), C(6), C(4), C(2),C(8)}, 
                      {C(3), C(9), C(8), C(3), C(7), C(6), C(2), C(3),C(9)}, 
                      {C(3), C(8), C(4), C(3), C(7), C(6), C(1), C(5),C(7)}, 
                      {C(3), C(8), C(5), C(3), C(7), C(5), C(3), C(8),C(3)}, 
                      {C(3), C(7), C(6), C(3), C(7), C(5), C(5), C(5),C(5)}, 
                     };
                     
  int value = isSudokuSolved(square);                 
  TEST_ASSERT_EQUAL(1,value);
}

void test_isSudokuSolve_return_0_one_square_contain_two_number(void){
  int square[9][9] = {{C(3), C(2), C(4), C(3), C(2), C(1), C(5), C(3),C(1)}, 
                      {C(3), C(8), C(1), C(3), C(7), C(6), C(4), C(6),C(5)},
                      {C(3), C(2), C(5), C(3)|C(2), C(7), C(6), C(4), C(3),C(1)}, 
                      {C(3), C(3), C(1), C(3), C(7), C(6), C(4), C(1),C(6)}, 
                      {C(3), C(1), C(7), C(3), C(7), C(6), C(4), C(2),C(8)}, 
                      {C(3), C(9), C(8), C(3), C(7), C(6), C(2), C(3),C(9)}, 
                      {C(3), C(8), C(4), C(3), C(7), C(6), C(1), C(5),C(7)}, 
                      {C(3), C(8), C(5), C(3), C(7), C(5), C(3), C(8),C(3)}, 
                      {C(3), C(7), C(6), C(3), C(7), C(5), C(5), C(5),C(5)}, 
                     };
                     
  int value = isSudokuSolved(square);                 
  TEST_ASSERT_EQUAL(0,value);
}

void test_selectSquareWithLeastValues_should_return_row_0(void){
  int square[9][9] = {{C(3), C(2)|C(3)|C(4), C(4), C(3),       C(2), C(1), C(5), C(3),C(1)|C(3)|C(5)}, 
                      {C(3), C(8),           C(1), C(3),       C(7), C(6), C(4), C(6),C(5)},
                      {C(3), C(2),           C(5), C(3),       C(7), C(6), C(4), C(3),C(1)}, 
                      {C(3), C(3),           C(1), C(3),       C(7), C(6), C(4), C(1),C(6)}, 
                      {C(3), C(1),           C(7), C(3),       C(7), C(6), C(4), C(2),C(8)}, 
                      {C(3), C(9),           C(8), C(3),       C(7), C(6), C(2), C(3),C(9)}, 
                      {C(3), C(8),           C(4), C(3),       C(7), C(6), C(1), C(5),C(7)}, 
                      {C(3), C(8),           C(5), C(3),       C(7), C(5), C(3), C(8),C(3)}, 
                      {C(3), C(7),           C(6), C(3),       C(7), C(5), C(5), C(5),C(5)|C(2)|C(4)}, 
                     };

  Square value = selectSquareWithLeastValues(square);
  TEST_ASSERT_EQUAL(0, value.row);
  TEST_ASSERT_EQUAL(1, value.column);
}
/*
void xtest_dumpSquare(void){
  int square[9][9] = {{C(3),     	    C(7),        C(9),   C(8), C(2), C(1), C(4), C(5), C(6)}, 
                      {C(5), 		      C(4),        C(8),   C(9), C(3), C(6), C(7), C(2), C(1)},
                      {C(2),          C(6),        C(1),   C(4), C(5), C(7), C(3), C(9), C(8)}, 
                      {C(1),          C(8),        C(5),   C(3), C(6), C(9), C(2), C(4), C(7)},  
                      {C(9),          C(2),        C(4),   C(1), C(7), C(5), C(8), C(6), C(3)},  
                      {C(6),          C(3),        C(7),   C(2), C(8), C(4), C(9), C(1), C(5)},  
                      {C(4),          C(9),        C(3),   C(5), C(1), C(8), C(6), C(7), C(2)},  
                      {C(8),          C(5),        C(6),   C(7), C(9), C(2), C(1), C(3), C(4)},  
                      {C(7),          C(1),        C(2),   C(6), C(4), C(3), C(5), C(8), C(9)}, 
                     };                 
  dumpSquare(square);
}*/

void test_nakedPair_eliminate_row(void){
    int square[9][9]={{C(1), C(2)|C(3),       C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //0 
                      {C(1), C(2)|C(4),       C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //1
                      {C(1), C(2)|C(4),       C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //2
                      
                      {C(1), C(2)|C(8)|C(5),  C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //3
                      {C(1), C(1),            C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //4
                      {C(1), C(6),            C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //5
                      
                      {C(1), C(5)|C(6),       C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //6
                      {C(1), C(1),            C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //7
                      {C(1), C(1),            C(1),  C(1), C(1), C(1), C(1), C(1),C(1)}, //8
                     }; 
  Square *row = rowPeers[0][1];
  eliminateNakedPairInPeers(square,row);
  
  TEST_ASSERT_EQUAL(4,square[0][1]);
  TEST_ASSERT_EQUAL(10,square[1][1]);
  TEST_ASSERT_EQUAL(10,square[2][1]);
  TEST_ASSERT_EQUAL(144,square[3][1]);
  TEST_ASSERT_EQUAL(1,square[4][1]);
  TEST_ASSERT_EQUAL(32,square[5][1]);
  TEST_ASSERT_EQUAL(48,square[6][1]);  
  TEST_ASSERT_EQUAL(1,square[7][1]);
  TEST_ASSERT_EQUAL(1,square[8][1]);  
}

void test_nakedPair_eliminate_column(void){
    int square[9][9]={{C(1), C(2)|C(3),   C(2)|C(4),  C(2), C(2)|C(3),  C(1)|C(8)|C(6), C(1), C(1),C(1)}, //0 
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //1
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //2
                      
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //3
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //4
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //5
                      
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //6
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //7
                      {C(1), C(1),        C(1),       C(1), C(1),       C(1),           C(1), C(1),C(1)}, //8
                     }; 
  Square *column = columnPeers[0][1];
  eliminateNakedPairInPeers(square,column);
  
  TEST_ASSERT_EQUAL(1,square[0][0]);
  TEST_ASSERT_EQUAL(6,square[0][1]);
  TEST_ASSERT_EQUAL(8,square[0][2]);
  TEST_ASSERT_EQUAL(2,square[0][3]);
  TEST_ASSERT_EQUAL(6,square[0][4]);
  TEST_ASSERT_EQUAL(161,square[0][5]);
  TEST_ASSERT_EQUAL(1,square[0][6]);  
  TEST_ASSERT_EQUAL(1,square[0][7]);
  TEST_ASSERT_EQUAL(1,square[0][8]);  
}

void test_nakedPair_eliminate_box(void){
    int square[9][9]={{C(1),      C(1),            C(1),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //0 
                      {C(1),      C(1),            C(1),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //1
                      {C(1),      C(1),            C(1),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //2
                      
                      {C(3),      C(7)|C(9),       C(2)|C(9),  C(1), C(1),  C(1),  C(1), C(1),C(1)}, //3
                      {C(5),      C(2)|C(8)|C(3),  C(8),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //4
                      {C(2)|C(9), C(6),            C(2),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //5
                      
                      {C(1),      C(1),            C(1),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //6
                      {C(1),      C(1),            C(1),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //7
                      {C(1),      C(1),            C(1),       C(1), C(1),  C(1),  C(1), C(1),C(1)}, //8
                     }; 
  Square *box = boxPeers[3][1];
  eliminateNakedPairInPeers(square,box);
  
  TEST_ASSERT_EQUAL(4,square[3][0]);
  TEST_ASSERT_EQUAL(64,square[3][1]);
  TEST_ASSERT_EQUAL(258,square[3][2]);
  TEST_ASSERT_EQUAL(16,square[4][0]);
  TEST_ASSERT_EQUAL(132,square[4][1]);
  TEST_ASSERT_EQUAL(128,square[4][2]);
  TEST_ASSERT_EQUAL(258,square[5][0]);  
  TEST_ASSERT_EQUAL(32,square[5][1]);
  TEST_ASSERT_EQUAL(2,square[5][2]);  
}

void test_nakedPair_eliminate_row_column_and_box(void){
    int square[9][9]={{C(6), C(2)|C(3),       C(2)|C(3),  C(1)      , C(1), C(1), C(1), C(1),C(1)}, //0 
                      {C(6), C(2)|C(4),       C(3),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //1
                      {C(1), C(2)|C(4),       C(1),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //2
                      
                      {C(1), C(2)|C(3),       C(1),       C(2)|C(9) , C(1), C(1), C(1), C(1),C(1)}, //3
                      {C(1), C(1),            C(1),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //4
                      {C(1), C(1),            C(1),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //5
                      
                      {C(1), C(5)|C(6),       C(1),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //6
                      {C(1), C(1),            C(1),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //7
                      {C(1), C(1),            C(1),       C(1)      , C(1), C(1), C(1), C(1),C(1)}, //8
                     }; 


  eliminateNakedPair(square);
  
  TEST_ASSERT_EQUAL(6,square[0][2]);
  TEST_ASSERT_EQUAL(4,square[1][2]);
  TEST_ASSERT_EQUAL(4,square[0][1]);
  TEST_ASSERT_EQUAL(32,square[0][0]);
  TEST_ASSERT_EQUAL(32,square[1][0]);
  TEST_ASSERT_EQUAL(4,square[3][1]);
  TEST_ASSERT_EQUAL(48,square[6][1]);  
  TEST_ASSERT_EQUAL(258,square[3][3]);
}

void test_eliminateNakedPair_with_successful_eliminate(void){
                  
  int square[9][9] = {{C(4)|C(9), C(8),           C(1),      C(3),           C(4)|C(5), C(6),      C(7),      C(2)     ,C(4)|C(5)|C(9)}, //0 
                      {C(4)|C(9), C(7),           C(6),      C(4)|C(5)|C(8), C(2),      C(5)|C(8), C(3),      C(1)     ,C(4)|C(5)|C(9)}, //1
                      {C(2),      C(3)|C(4)|C(5), C(3)|C(5), C(7),           C(1),      C(9),      C(4)|C(5), C(6)     ,C(8)}, //2
                      
                      {C(6),      C(2)|C(4)|C(5), C(2)|C(5), C(9),           C(7),      C(3),      C(4)|C(5), C(8)     ,C(1)}, //3
                      {C(1),      C(4)|C(5),      C(7),      C(4)|C(5)|C(8), C(6),      C(5)|C(8), C(9),      C(3)     ,C(2)}, //4
                      {C(3),      C(9),           C(8),      C(1),           C(4)|C(5), C(2),      C(6),      C(4)|C(5),C(7)}, //5
                      
                      {C(5),      C(1),           C(9),      C(2),           C(3),      C(4),      C(8),      C(7)     ,C(6)}, //6
                      {C(7),      C(3)|C(6),      C(4),      C(5)|C(6),      C(8),      C(1),      C(2),      C(9)     ,C(3)|C(5)}, //7
                      {C(8),      C(2)|C(3)|C(6), C(2)|C(3), C(5)|C(6),      C(9),      C(7),      C(1),      C(4)|C(5),C(3)|C(4)|C(5)}, //8
                    }; 
              
            
  eliminateNakedPair(square);  

  TEST_ASSERT_EQUAL(256, square[0][0]);
  TEST_ASSERT_EQUAL(8, square[1][0]);
  TEST_ASSERT_EQUAL(4, square[2][1]);
  TEST_ASSERT_EQUAL(8, square[3][1]);
  TEST_ASSERT_EQUAL(16, square[4][1]);
  TEST_ASSERT_EQUAL(32, square[7][1]);
  
  TEST_ASSERT_EQUAL(2, square[8][1]);
  TEST_ASSERT_EQUAL(16, square[2][2]);
  TEST_ASSERT_EQUAL(2, square[3][2]);
  TEST_ASSERT_EQUAL(4, square[8][2]);
  TEST_ASSERT_EQUAL(128, square[1][3]);
  TEST_ASSERT_EQUAL(8, square[4][3]);
  
  TEST_ASSERT_EQUAL(16, square[7][3]);
  TEST_ASSERT_EQUAL(32, square[8][3]);
  TEST_ASSERT_EQUAL(8, square[0][4]);
  TEST_ASSERT_EQUAL(16, square[5][4]);
  TEST_ASSERT_EQUAL(16, square[1][5]);
  TEST_ASSERT_EQUAL(128, square[4][5]);
  
  TEST_ASSERT_EQUAL(8, square[2][6]);
  TEST_ASSERT_EQUAL(16, square[3][6]);
  TEST_ASSERT_EQUAL(8, square[5][7]);
  TEST_ASSERT_EQUAL(16, square[8][7]);
  TEST_ASSERT_EQUAL(16, square[0][8]);
  TEST_ASSERT_EQUAL(256, square[1][8]);
  
  TEST_ASSERT_EQUAL(4, square[7][8]);
  TEST_ASSERT_EQUAL(8, square[8][8]);
}

void test_bruteForce_with_successful_eliminate(void){
                    //  0           1               2          3                4         5          6          7         8
  int square[9][9] = {{C(4)|C(9), C(8),           C(1),      C(3),           C(4)|C(5), C(6),      C(7),      C(2)     ,C(4)|C(5)|C(9)}, //0 
                      {C(4)|C(9), C(7),           C(6),      C(4)|C(5)|C(8), C(2),      C(5)|C(8), C(3),      C(1)     ,C(4)|C(5)|C(9)}, //1
                      {C(2),      C(3)|C(4)|C(5), C(3)|C(5), C(7),           C(1),      C(9),      C(4)|C(5), C(6)     ,C(8)}, //2
                      
                      {C(6),      C(2)|C(4)|C(5), C(2)|C(5), C(9),           C(7),      C(3),      C(4)|C(5), C(8)     ,C(1)}, //3
                      {C(1),      C(4)|C(5),      C(7),      C(4)|C(5)|C(8), C(6),      C(5)|C(8), C(9),      C(3)     ,C(2)}, //4
                      {C(3),      C(9),           C(8),      C(1),           C(4)|C(5), C(2),      C(6),      C(4)|C(5),C(7)}, //5
                      
                      {C(5),      C(1),           C(9),      C(2),           C(3),      C(4),      C(8),      C(7)     ,C(6)}, //6
                      {C(7),      C(3)|C(6),      C(4),      C(5)|C(6),      C(8),      C(1),      C(2),      C(9)     ,C(3)|C(5)}, //7
                      {C(8),      C(2)|C(3)|C(6), C(2)|C(3), C(5)|C(6),      C(9),      C(7),      C(1),      C(4)|C(5),C(3)|C(4)|C(5)}, //8
                     }; 

  eliminateNakedPair(square);  

  TEST_ASSERT_EQUAL(256, square[0][0]);
  TEST_ASSERT_EQUAL(8, square[1][0]);
  TEST_ASSERT_EQUAL(4, square[2][1]);
  TEST_ASSERT_EQUAL(8, square[3][1]);
  TEST_ASSERT_EQUAL(16, square[4][1]);
  TEST_ASSERT_EQUAL(32, square[7][1]);
  
  TEST_ASSERT_EQUAL(2, square[8][1]);
  TEST_ASSERT_EQUAL(16, square[2][2]);
  TEST_ASSERT_EQUAL(2, square[3][2]);
  TEST_ASSERT_EQUAL(4, square[8][2]);
  TEST_ASSERT_EQUAL(128, square[1][3]);
  TEST_ASSERT_EQUAL(8, square[4][3]);
  
  TEST_ASSERT_EQUAL(16, square[7][3]);
  TEST_ASSERT_EQUAL(32, square[8][3]);
  TEST_ASSERT_EQUAL(8, square[0][4]);
  TEST_ASSERT_EQUAL(16, square[5][4]);
  TEST_ASSERT_EQUAL(16, square[1][5]);
  TEST_ASSERT_EQUAL(128, square[4][5]);
  
  TEST_ASSERT_EQUAL(8, square[2][6]);
  TEST_ASSERT_EQUAL(16, square[3][6]);
  TEST_ASSERT_EQUAL(8, square[5][7]);
  TEST_ASSERT_EQUAL(16, square[8][7]);
  TEST_ASSERT_EQUAL(16, square[0][8]);
  TEST_ASSERT_EQUAL(256, square[1][8]);
  
  TEST_ASSERT_EQUAL(4, square[7][8]);
  TEST_ASSERT_EQUAL(8, square[8][8]);
}

void test_bruteForce_with_successful_eliminate_1(void){
                    //  0                 1               2                     3          4                5          6                    7               8
  int square[9][9] = {{C(2)|C(5),       C(3),           C(7),                 C(4),      C(8),            C(1),      C(6),                C(2)|C(5),      C(9)}, //0 
                      {C(1)|C(6),       C(9),           C(1)|C(4)|C(5)|C(6),  C(5)|C(6), C(2),            C(7),      C(1)|C(4),           C(3),           C(8)}, //1
                      {C(8),            C(2)|C(4)|C(5), C(1)|C(4)|C(5)|C(6),  C(3),      C(5)|C(6),       C(9),      C(1)|C(2)|C(4)|C(7), C(2)|C(4)|C(5), C(1)|C(2)|C(4)|C(7)}, //2
                      
                      {C(2)|C(4)|C(5),  C(1),           C(9),                 C(8),      C(7),            C(3),      C(2)|C(4)|C(5),      C(6),           C(4)|C(2)}, //3
                      {C(7),            C(8),           C(4)|C(5)|C(6),       C(5)|C(6), C(1)|C(5)|C(6),  C(2),      C(1)|C(4)|C(5),      C(9),           C(3)}, //4
                      {C(3)|C(6),       C(2)|C(5),      C(3)|C(5)|C(6),       C(9),      C(1)|C(5)|C(6),  C(4),      C(8),                C(7),           C(1)|C(2)}, //5
                      
                      {C(1)|C(3),       C(4)|C(7),      C(1)|C(3),            C(2),      C(9),            C(5),      C(4)|C(7),           C(8),           C(6)}, //6
                      {C(4)|C(5),       C(4)|C(5)|C(7), C(8),                 C(1),      C(3),            C(6),      C(9),                C(2)|C(4),      C(2)|C(4)|C(7)}, //7
                      {C(9),            C(6),           C(2),                 C(7),      C(4),            C(8),      C(3),                C(1),           C(5)}, //8
                     }; 
              
            
  eliminateNakedPair(square);  

  TEST_ASSERT_EQUAL(2, square[0][0]);
  TEST_ASSERT_EQUAL(32, square[1][0]);
  TEST_ASSERT_EQUAL(8, square[3][0]);
  TEST_ASSERT_EQUAL(4, square[5][0]);
  TEST_ASSERT_EQUAL(1, square[6][0]);
  
  TEST_ASSERT_EQUAL(16, square[2][1]);
  TEST_ASSERT_EQUAL(2, square[5][1]);
  TEST_ASSERT_EQUAL(8, square[6][1]);
  TEST_ASSERT_EQUAL(64, square[7][1]);
  
  TEST_ASSERT_EQUAL(8, square[1][2]);
  TEST_ASSERT_EQUAL(1, square[2][2]);
  TEST_ASSERT_EQUAL(16, square[4][2]);
  TEST_ASSERT_EQUAL(32, square[5][2]);
  TEST_ASSERT_EQUAL(4, square[6][2]);
  
  TEST_ASSERT_EQUAL(16, square[1][3]);
  TEST_ASSERT_EQUAL(32, square[4][3]);
  
  TEST_ASSERT_EQUAL(32, square[2][4]);
  TEST_ASSERT_EQUAL(1, square[4][4]);
  TEST_ASSERT_EQUAL(16, square[5][4]);
  
  TEST_ASSERT_EQUAL(1, square[1][6]);
  TEST_ASSERT_EQUAL(2, square[2][6]);
  TEST_ASSERT_EQUAL(16, square[3][6]);
  TEST_ASSERT_EQUAL(8, square[4][6]);
  TEST_ASSERT_EQUAL(64, square[6][6]);
  
  TEST_ASSERT_EQUAL(16, square[0][7]);
  TEST_ASSERT_EQUAL(8, square[2][7]);
  TEST_ASSERT_EQUAL(2, square[7][7]);
  
  TEST_ASSERT_EQUAL(64, square[2][8]);
  TEST_ASSERT_EQUAL(2, square[3][8]);
  TEST_ASSERT_EQUAL(1, square[5][8]);
  TEST_ASSERT_EQUAL(8, square[7][8]);
}

void test_bruteForce_with_successful_eliminate_2(void){
                    //  0     1                     2                    3                              4                     5                         6                                   7                             8
  int square[9][9] = {{C(1), C(6)|C(9),           C(6)|C(7)|C(9),      C(2)|C(4)|C(9),                C(8),                 C(5),                     C(2)|C(4)|C(7)|C(9),                C(2)|C(7)|C(9),                 C(3)}, //0 
                      {C(2), C(4),                C(3)|C(8)|C(9),      C(1)|C(3)|C(6)|C(9),           C(7),                 C(1)|C(3)|C(6),           C(1)|C(6)|C(8)|C(9),                C(5),                           C(1)|C(6)|C(8)|C(9)}, //1
                      {C(5), C(3)|C(8)|C(9),      C(3)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(6)|C(9), C(1)|C(3)|C(6)|C(9),  C(1)|C(2)|C(3)|C(6),      C(1)|C(2)|C(4)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(4)|C(6)|C(8)|C(9)}, //2
                      
                      {C(7), C(1)|C(2)|C(6)|C(8), C(4),                C(5),                          C(1)|C(3)|C(6),       C(9),                     C(1)|C(2)|C(3)|C(6)|C(8),           C(1)|C(2)|C(6)|C(8),            C(1)|C(2)|C(6)|C(8)}, //3
                      {C(9), C(5),                C(1)|C(6),           C(1)|C(3)|C(6)|C(8),           C(2),                 C(1)|C(3)|C(6)|C(8),      C(1)|C(3)|C(6),                     C(4),                           C(7)}, //4
                      {C(3), C(1)|C(2)|C(6)|C(8), C(1)|C(2)|C(6)|C(8), C(7),                          C(1)|C(6),            C(4),                     C(5),                               C(1)|C(2)|C(6)|C(8)|C(9),       C(1)|C(2)|C(6)|C(8)|C(9)}, //5
                      
                      {C(8), C(1)|C(2)|C(3)|C(9), C(5),                C(1)|C(2)|C(3)|C(6)|C(9),      C(1)|C(3)|C(6)|C(9),  C(1)|C(2)|C(3)|C(6)|C(7), C(1)|C(2)|C(4)|C(6)|C(7)|C(9),      C(1)|C(2)|C(6)|C(7)|C(9),       C(1)|C(2)|C(4)|C(6)|C(9)}, //6
                      {C(4), C(7),                C(1)|C(2)|C(9),      C(1)|C(2)|C(6)|C(8)|C(9),      C(5),                 C(1)|C(3)|C(6)|C(8),      C(1)|C(2)|C(6)|C(8)|C(9),           C(3),                           C(1)|C(2)|C(6)|C(8)|C(9)}, //7
                      {C(6), C(1)|C(2)|C(3)|C(9), C(1)|C(2)|C(3)|C(9), C(1)|C(2)|C(3)|C(8)|C(9),      C(4),                 C(1)|C(2)|C(3)|C(7)|C(8), C(1)|C(2)|C(7)|C(8)|C(9),           C(1)|C(2)|C(7)|C(8)|C(9),       C(5)}, //8
                     }; 
              
            
  eliminateNakedPair(square);  

  TEST_ASSERT_EQUAL(1, square[0][0]);
  TEST_ASSERT_EQUAL(256, square[0][1]);
  TEST_ASSERT_EQUAL(4, square[2][1]);
  TEST_ASSERT_EQUAL(128, square[3][1]);
  TEST_ASSERT_EQUAL(32, square[5][1]);
  TEST_ASSERT_EQUAL(2, square[6][1]);
  TEST_ASSERT_EQUAL(1, square[8][1]);
  
  TEST_ASSERT_EQUAL(32, square[0][2]);
  TEST_ASSERT_EQUAL(128, square[1][2]);
  TEST_ASSERT_EQUAL(64, square[2][2]);
  TEST_ASSERT_EQUAL(1, square[4][2]);
  TEST_ASSERT_EQUAL(2, square[5][2]);
  TEST_ASSERT_EQUAL(256, square[7][2]);
  TEST_ASSERT_EQUAL(4, square[8][2]);
  
  TEST_ASSERT_EQUAL(8, square[0][3]);
  TEST_ASSERT_EQUAL(4, square[1][3]);
  TEST_ASSERT_EQUAL(32, square[2][3]);
  TEST_ASSERT_EQUAL(128, square[4][3]);
  TEST_ASSERT_EQUAL(1, square[6][3]);
  TEST_ASSERT_EQUAL(2, square[7][3]);
  TEST_ASSERT_EQUAL(256, square[8][3]);
  
  TEST_ASSERT_EQUAL(256, square[2][4]);
  TEST_ASSERT_EQUAL(32, square[3][4]);
  TEST_ASSERT_EQUAL(1, square[5][4]);
  TEST_ASSERT_EQUAL(4, square[6][4]);
  
  TEST_ASSERT_EQUAL(1, square[1][5]);
  TEST_ASSERT_EQUAL(2, square[2][5]);
  TEST_ASSERT_EQUAL(4, square[4][5]);
  TEST_ASSERT_EQUAL(64, square[6][5]);
  TEST_ASSERT_EQUAL(32, square[7][5]);
  TEST_ASSERT_EQUAL(128, square[8][5]);
  
  TEST_ASSERT_EQUAL(64, square[0][6]);
  TEST_ASSERT_EQUAL(256, square[1][6]);
  TEST_ASSERT_EQUAL(1, square[2][6]);
  TEST_ASSERT_EQUAL(4, square[3][6]);
  TEST_ASSERT_EQUAL(32, square[4][6]);
  TEST_ASSERT_EQUAL(8, square[6][6]);
  TEST_ASSERT_EQUAL(128, square[7][6]);
  TEST_ASSERT_EQUAL(2, square[8][6]);
  
  TEST_ASSERT_EQUAL(2, square[0][7]);
  TEST_ASSERT_EQUAL(128, square[2][7]);
  TEST_ASSERT_EQUAL(1, square[3][7]);
  TEST_ASSERT_EQUAL(256, square[5][7]);
  TEST_ASSERT_EQUAL(32, square[6][7]);
  TEST_ASSERT_EQUAL(64, square[8][7]);
  
  TEST_ASSERT_EQUAL(32, square[1][8]);
  TEST_ASSERT_EQUAL(8, square[2][8]);
  TEST_ASSERT_EQUAL(2, square[3][8]);
  TEST_ASSERT_EQUAL(128, square[5][8]);
  TEST_ASSERT_EQUAL(256, square[6][8]);
  TEST_ASSERT_EQUAL(1, square[7][8]);

}

void test_grids(void){
  char read[81] = "1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..";
  int square[9][9];
  clearSquares(square);  

  grids(read, square);
  TEST_ASSERT_EQUAL(1,square[0][0]);
}

void test_grids_should_fail(void){
  char read[81] = "1 .2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..";
  int square[9][9];
  clearSquares(square);  
  ErrorCode e;
  
  
  Try{
    grids(read, square);
    TEST_ASSERT_EQUAL(1,square[0][1]);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_INVALID_NUM, e);
  }
}

void test_grids_Alphabet(void){
  char read[81] = "A..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..";
  int square[9][9];
  clearSquares(square);  
  ErrorCode e;
  Try{
    grids(read, square);
    TEST_ASSERT_EQUAL(1,square[0][1]);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_INVALID_NUM, e);
  }
}

/*
void test_bruteForce_with_successful_eliminate_3(void){
                     0                                              1                                              2                                             3                                               4                                              5                                              6                                             7                             8
  int square[9][9] = {{C(4),                                         C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),   C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(8),                                         C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(5)}, //0 
                      {C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(3),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),   C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //1
                      {C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(7),                                           C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //2
                      
                      {C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(2),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),   C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(6),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //3
                      {C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),   C(8),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(4),                                         C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //4
                      {C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),   C(1),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //5
                      
                      {C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(6),                                           C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(3),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(7),                                          C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //6
                      {C(5),                                         C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(2),                                           C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //7
                      {C(1),                                         C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(4),                                         C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),   C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9), C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9),  C(1)|C(2)|C(3)|C(4)|C(5)|C(6)|C(7)|C(8)|C(9)}, //8
                     }; 
              
            
  eliminateBruteForce(square);
}*/
void xtest_bruteForce_5(void){
                    //  0                                      1                                     2                     3                                               4                         5                                              6                               7                                           8
  int square[9][9] = {{C(2)|C(3)|C(4)|C(7)|C(9),            C(3)|C(6)|C(7)|C(9),         C(4)|C(6)|C(7)|C(9),           C(8),                                     C(2)|C(4)|C(9),                   C(1),                                         C(5),                          C(2)|C(6)|C(9),                               C(2)|C(6)|C(9)}, //0 
                      {C(1)|C(2)|C(8)|C(9),                 C(1)|C(6)|C(8)|C(9),         C(1)|C(6)|C(8)|C(9),           C(7),                                     C(2)|C(9),                        C(5),                                         C(2)|C(9),                     C(4),                                         C(3)}, //1
                      {C(5),                                C(1)|C(8)|C(9),              C(1)|C(4)|C(8)|C(9),           C(3),                                     C(2)|C(4)|C(9),                   C(6),                                         C(7),                          C(1)|C(2)|C(8)|C(9),                          C(1)|C(2)|C(8)|C(9)}, //2
                      
                      {C(1)|C(3)|C(4)|C(9),                 C(1)|C(3)|C(6)|C(9),         C(1)|C(4)|C(5)|C(6)|C(9),      C(1)|C(5)|C(6),                           C(7),                             C(2)|C(4),                                    C(8),                          C(2)|C(3)|C(5)|C(6)|C(9),                     C(2)|C(6)|C(9)}, //3
                      {C(3)|C(4)|C(7)|C(9),                 C(3)|C(6)|C(7)|C(9),         C(4)|C(5)|C(6)|C(7)|C(9),      C(5)|C(6),                                C(8),                             C(2)|C(4),                                    C(1),                          C(2)|C(3)|C(5)|C(6)|C(9),                     C(2)|C(6)|C(7)|C(9)}, //4
                      {C(1)|C(7)|C(8),                      C(2),                        C(1)|C(5)|C(6)|C(7)|C(8),      C(1)|C(5)|C(6),                           C(3),                             C(9),                                         C(4),                          C(5)|C(6),                                    C(6)|C(7)}, //5
                      
                      {C(6),                                C(4),                        C(2),                          C(9),                                     C(1),                             C(8),                                         C(3),                          C(7),                                         C(5)}, //6
                      {C(1)|C(8)|C(9),                      C(5),                        C(3),                          C(4),                                     C(6),                             C(7),                                         C(2)|C(9),                     C(1)|C(2)|C(8)|C(9),                          C(1)|C(2)|C(8)|C(9)}, //7
                      {C(1)|C(7)|C(8)|C(9),                 C(1)|C(7)|C(8)|C(9),         C(1)|C(7)|C(8)|C(9),           C(2),                                     C(5),                             C(3),                                         C(6),                          C(1)|C(8)|C(9),                               C(4)}, //8
                     }; 
              
            
  eliminateBruteForce(square);
  dumpSquare(square);
  // TEST_ASSERT_EQUAL(2, square[1][0]);
  // TEST_ASSERT_EQUAL(32, square[2][0]);
  // TEST_ASSERT_EQUAL(256, square[3][0]);
  // TEST_ASSERT_EQUAL(256, square[4][0]);
  
}
/*
void test_bruteForce_6(void){
                    //  0                       1                 2                     3                           4                          5                       6                               7                                           8
  int square[9][9] = {{C(1)|C(4)|C(8),       C(2),              C(6),                   C(5),                    C(3)|C(4)|C(8),            C(3)|C(4),               C(3)|C(7),                    C(9),                               C(1)|C(3)|C(8)}, //0 
                      {C(5),                 C(8),              C(1)|C(8),              C(6)|C(8),               C(7),                      C(9),                    C(2)|C(3)|C(6),               C(2)|C(3)|C(6)|C(8),                C(4)}, //1
                      {C(3),                 C(4)|C(8)|C(9),    C(4)|C(7)|C(8)|C(9),    C(4)|C(6)|C(8),          C(1),                      C(2)|C(4)|C(6),          C(2)|C(5)|C(6)|C(7),          C(2)|C(5)|C(6)|C(7)|C(8),           C(5)|C(6)|C(8)}, //2
                      
                      {C(6),                 C(4)|C(9),         C(2)|C(3)|C(4)|C(9),    C(1)|C(4)|C(9),          C(3)|C(4)|C(5)|C(9),       C(1)|C(3)|C(4)|C(5),     C(8),                         C(2)|C(3)|C(5),                     C(7)}, //3
                      {C(4)|C(8)|C(9),       C(7),              C(5),                   C(4)|C(6)|C(8)|C(9),     C(2),                      C(3)|C(4)|C(6),          C(3)|C(6),                    C(1),                               C(3)|C(6)|C(9)}, //4
                      {C(2)|C(8)|C(9),       C(1),              C(2)|C(3)|C(8)|C(9),    C(6)|C(7)|C(8)|C(9),     C(3)|C(5)|C(8)|C(9),       C(3)|C(5)|C(6)|C(7),     C(4),                         C(2)|C(3)|C(5)|C(6),                C(3)|C(5)|C(6)|C(9)}, //5
                      
                      {C(1)|C(4),            C(4)|C(5)|C(6),    C(1)|C(4),              C(3),                    C(4)|C(5),                 C(8),                    C(9),                         C(5)|C(6)|C(7),                      C(2)}, //6
                      {C(7),                 C(5)|C(8)|C(9),    C(1)|C(2)|C(8)|C(9),    C(1)|C(9),               C(6),                      C(1)|C(5),               C(3)|C(5),                    C(4),                                C(3)|C(5)|C(8)}, //7
                      {C(4)|C(8)|C(9),       C(3),              C(4)|C(8)|C(9),         C(2),                    C(4)|C(5)|C(9),            C(4)|C(5)|C(7),          C(1),                         C(5)|C(6)|C(7)|C(8),                 C(5)|C(6)|C(8)}, //8
                     }; 
              
            
  eliminateNakedPair(square);
  dumpSquare(square);
  // TEST_ASSERT_EQUAL(2, square[1][0]);
  // TEST_ASSERT_EQUAL(32, square[2][0]);
  // TEST_ASSERT_EQUAL(256, square[3][0]);
  // TEST_ASSERT_EQUAL(256, square[4][0]);
  
  
}*/



//////////////////////////////////////////////////////////////////
// Test code for nakedTriple and nakedQuad works for individual //
//////////////////////////////////////////////////////////////////
void test_nakedTriples_eliminate_row(void){
    int square[9][9]={{C(1), C(2)|C(3)|C(4),       C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //0 
                      {C(1), C(2)|C(3)|C(4),       C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //1
                      {C(1), C(2)|C(4)|C(8)|C(1),  C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //2
                      
                      {C(1), C(2)|C(8)|C(5),       C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //3
                      {C(1), C(1),                 C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //4
                      {C(1), C(6),                 C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //5
                      
                      {C(1), C(5)|C(6),            C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //6
                      {C(1), C(2)|C(3),            C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //7
                      {C(1), C(1),                 C(1),       C(1), C(1), C(1),  C(1), C(1),C(1)}, //8
                     }; 

    Square *row = rowPeers[0][1];
    eliminateNakedTriplesInPeers(square,row);

    TEST_ASSERT_EQUAL(14,square[0][1]);
    TEST_ASSERT_EQUAL(14,square[1][1]);
    TEST_ASSERT_EQUAL(129,square[2][1]);
    TEST_ASSERT_EQUAL(144,square[3][1]);
    TEST_ASSERT_EQUAL(1,square[4][1]);
    TEST_ASSERT_EQUAL(32,square[5][1]);
    TEST_ASSERT_EQUAL(48,square[6][1]);  
    TEST_ASSERT_EQUAL(6,square[7][1]);
    TEST_ASSERT_EQUAL(1,square[8][1]);  

}

void test_nakedTriples_eliminate_column(void){
    int square[9][9]={{C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //0 
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //1
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //2
                      
                      {C(7)|C(9)|C(8)      ,       C(7)|C(9)|C(8)     ,       C(7)|C(8), C(3)|C(9)|C(5), C(4),       C(5)|C(6)|C(8)|C(9),           C(7)|C(9), C(2),C(3)|C(5)|C(6)|C(7)|C(8)|C(9)}, //3
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //4
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //5
                      
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //6
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //7
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //8
                     }; 
  
    Square *col = columnPeers[3][0];
    eliminateNakedTriplesInPeers(square,col);
    
    TEST_ASSERT_EQUAL(448,square[3][0]);
    TEST_ASSERT_EQUAL(448,square[3][1]);
    TEST_ASSERT_EQUAL(192,square[3][2]);
    TEST_ASSERT_EQUAL(20,square[3][3]);
    TEST_ASSERT_EQUAL(8,square[3][4]);
    TEST_ASSERT_EQUAL(48,square[3][5]);
    TEST_ASSERT_EQUAL(320,square[3][6]);  
    TEST_ASSERT_EQUAL(2,square[3][7]);
    TEST_ASSERT_EQUAL(52,square[3][8]);  
}

void test_nakedTriples_eliminate(void){
    int square[9][9]={{C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //0 
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //1
                      {C(2)|C(9)|C(8), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //2
                      
                      {C(2)|C(9)|C(8), C(2)|C(9)|C(8),       C(3)|C(8),       C(2)|C(9)|C(8)     , C(1),       C(1),           C(1), C(1),C(1)}, //3
                      {C(1)          , C(1)          ,       C(2)|C(3)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //4
                      {C(1)          , C(1)          ,       C(2)|C(9)|C(8)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //5
                      
                      {C(2)|C(9)|C(8), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //6
                      {C(1), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //7
                      {C(2)|C(6), C(1)          ,       C(1)     ,       C(1)     , C(1),       C(1),           C(1), C(1),C(1)}, //8
                     }; 
  

    eliminateNakedTriples(square);
    
    TEST_ASSERT_EQUAL(386,square[2][0]);
    TEST_ASSERT_EQUAL(386,square[3][0]);
    TEST_ASSERT_EQUAL(386,square[6][0]);
    TEST_ASSERT_EQUAL(34,square[8][0]);
    TEST_ASSERT_EQUAL(132,square[3][2]);
    TEST_ASSERT_EQUAL(6,square[4][2]);
  
}

void test_nakedQuad_eliminate_row(void){
    int square[9][9]={{C(1), C(2)|C(9),           C(1), C(1), C(1), C(1), C(1), C(1),C(1)}, //0 
                      {C(1), C(2)|C(4)|C(3)|C(6), C(1), C(1), C(1), C(1), C(1), C(1),C(1)}, //1
                      {C(1), C(2)|C(4)|C(3)|C(6), C(1), C(1), C(1), C(1), C(1), C(1),C(1)}, //2
                      
                      {C(1), C(2)|C(8)|C(5),      C(1), C(1), C(1), C(1), C(1), C(1),C(1)}, //3
                      {C(1), C(1),                C(1), C(1), C(1), C(1), C(1), C(1),C(1)}, //4
                      {C(1), C(6),                C(1), C(1), C(1), C(1), C(1), C(1),C(1)}, //5
                      
                      {C(1), C(5)|C(6),           C(1), C(1), C(1), C(1),  C(1), C(1),C(1)}, //6
                      {C(1), C(1),                C(1), C(1), C(1), C(1),  C(1), C(1),C(1)}, //7
                      {C(1), C(1),                C(1), C(1), C(1), C(1),  C(1), C(1),C(1)}, //8
                     }; 
  Square *row = rowPeers[0][1];
  eliminateNakedQuadInPeers(square,row);
  
  TEST_ASSERT_EQUAL(256,square[0][1]);
  TEST_ASSERT_EQUAL(46,square[1][1]);
  TEST_ASSERT_EQUAL(46,square[2][1]);
  TEST_ASSERT_EQUAL(144,square[3][1]);
  TEST_ASSERT_EQUAL(1,square[4][1]);
  TEST_ASSERT_EQUAL(32,square[5][1]);
  TEST_ASSERT_EQUAL(16,square[6][1]);  
  TEST_ASSERT_EQUAL(1,square[7][1]);
  TEST_ASSERT_EQUAL(1,square[8][1]);  
}

void test_nakedQuad_eliminate(void){
    int square[9][9]={{C(1),                C(1),                 C(1),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //0 
                      {C(1),                C(1),                 C(1),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //1
                      {C(1),                C(2)|C(3)|C(4)|C(5),  C(1),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //2
                      
                      {C(2)|C(3)|C(4)|C(5), C(2)|C(3)|C(4)|C(5),  C(3)|C(8),            C(2)|C(9)|C(8),       C(1),                 C(1), C(1), C(1),C(1)}, //3
                      {C(2)|C(3)|C(4)|C(5), C(1),                 C(2),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //4
                      {C(2)|C(8)|C(9),      C(2)|C(3)|C(4)|C(5),  C(2)|C(3)|C(4)|C(5),  C(2)|C(3)|C(4)|C(5),  C(2)|C(3)|C(4)|C(5),  C(1), C(1), C(1),C(1)}, //5
                      
                      {C(1),                C(2)|C(6),            C(1),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //6
                      {C(1),                C(2)|C(3)|C(4)|C(5),  C(1),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //7
                      {C(2),                C(1),                 C(1),                 C(1),                 C(1),                 C(1), C(1), C(1),C(1)}, //8
                     }; 
  

    eliminateNakedQuad(square);
    
    TEST_ASSERT_EQUAL(30,square[3][0]);
    TEST_ASSERT_EQUAL(30,square[4][0]);
    TEST_ASSERT_EQUAL(384,square[5][0]);
    TEST_ASSERT_EQUAL(30,square[3][1]);
    TEST_ASSERT_EQUAL(128,square[3][2]);
    TEST_ASSERT_EQUAL(2,square[4][2]);
  
}

////////////////////////////////////////////////////////
// Test code for search but function not complete yet //
////////////////////////////////////////////////////////
void test_searchPosibilityValueOfEmptySquare_in_peers(void){
  char read[81] = "1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..1..2..3..";
  int square[9][9];
  clearSquares(square);
  grids(read, square);
  Square *peersRow = rowPeers[0][0];
  searchPossibilityValueOfEmptySquareInPeers(square,peersRow);
  dumpSquare(square);
  // TEST_ASSERT_EQUAL(192, square[0][1]);
}
/*
void xtest_searchPosibilityValueOfEmptySquare(void){
  int square[9][9] = {{C(0),     	    C(3),        C(7),   C(4), C(8), C(1), C(6), C(0), C(9)}, 
                      {C(0), 		      C(9),        C(0),   C(0), C(2), C(7), C(0), C(3), C(8)},
                      {C(8),          C(0),        C(0),   C(3), C(0), C(9), C(0), C(0), C(0)}, 
                      {C(0),          C(1),        C(9),   C(8), C(7), C(3), C(0), C(6), C(0)},  
                      {C(7),          C(8),        C(0),   C(0), C(0), C(2), C(0), C(9), C(3)},  
                      {C(0),          C(0),        C(0),   C(9), C(0), C(4), C(8), C(7), C(0)},  
                      {C(0),          C(0),        C(0),   C(2), C(9), C(5), C(0), C(8), C(6)},  
                      {C(0),          C(0),        C(8),   C(1), C(3), C(6), C(9), C(0), C(0)},  
                      {C(9),          C(6),        C(2),   C(7), C(4), C(8), C(3), C(1), C(5)}, 
                     };                 

  searchPossibilityValueOfEmptySquare(square);
  TEST_ASSERT_EQUAL(192, square[0][0]);
}
*/