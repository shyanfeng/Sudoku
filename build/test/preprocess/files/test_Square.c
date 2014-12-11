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



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((*valuePtr)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

}



void test_getSquare_should_enter_column_6_row_4_and_return_7(void){

 int column = 6;

 int row = 4;

 int square[9][9];

 int *valuePtr;



 square[row-1][column-1] = 7;

 valuePtr = getSquare(square, row, column);



 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*valuePtr)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

}



void test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3_2_1_4(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 2, 1), 3);

  squareSetNumber(getSquare(square, 2, 1), 2);

  squareSetNumber(getSquare(square, 2, 1), 1);

  squareSetNumber(getSquare(square, 2, 1), 4);



 UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((square[1][0])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

}



void test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4_2_6(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 3, 8), 4);

 squareSetNumber(getSquare(square, 3, 8), 2);

 squareSetNumber(getSquare(square, 3, 8), 6);



 UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((square[2][7])), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

}



void test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2_7_8(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 9, 9), 2);

 squareSetNumber(getSquare(square, 9, 9), 7);

 squareSetNumber(getSquare(square, 9, 9), 8);



 UnityAssertEqualNumber((_U_SINT)((194)), (_U_SINT)((square[8][8])), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

}



void test_squareDelNumber_should_enter_column_4_row_2_and_del_bit_5(void){

  int square[9][9];

  clearSquares(square);



  squareSetNumber(getSquare(square, 4, 2), 5);

  squareSetNumber(getSquare(square, 4, 2), 8);

  squareSetNumber(getSquare(square, 4, 2), 1);



  UnityAssertEqualNumber((_U_SINT)((145)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);



 squareDelNumber(getSquare(square, 4, 2), 5);



 UnityAssertEqualNumber((_U_SINT)((129)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

}



void test_squareDelNumber_should_enter_column_9_row_9_and_del_bit_6(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 9, 9), 6);

 squareSetNumber(getSquare(square, 9, 9), 2);

 squareSetNumber(getSquare(square, 9, 9), 7);



 UnityAssertEqualNumber((_U_SINT)((98)), (_U_SINT)((square[8][8])), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);



 squareDelNumber(getSquare(square, 9, 9), 6);



 UnityAssertEqualNumber((_U_SINT)((66)), (_U_SINT)((square[8][8])), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

}



void test_squareDelNumber_should_enter_column_5_row_1_and_del_bit_2_4(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 5, 1), 2);

 squareSetNumber(getSquare(square, 5, 1), 4);

 squareSetNumber(getSquare(square, 5, 1), 7);



 UnityAssertEqualNumber((_U_SINT)((74)), (_U_SINT)((square[4][0])), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);



 squareDelNumber(getSquare(square, 5, 1), 2);

 squareDelNumber(getSquare(square, 5, 1), 4);



 UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((square[4][0])), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}



void test_removeOthersExcept_should_enter_column_4_row_2_and_remove_all_except_4(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 4, 2), 2);

 squareSetNumber(getSquare(square, 4, 2), 4);

 squareSetNumber(getSquare(square, 4, 2), 7);



 UnityAssertEqualNumber((_U_SINT)((74)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);



 removeOthersExcept(getSquare(square, 4, 2), 2);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

}



void test_removeOthersExcept_should_enter_column_7_row_3_and_remove_all_except_4(void){

 int square[9][9];

  clearSquares(square);



 squareSetNumber(getSquare(square, 7, 2), 8);

 squareSetNumber(getSquare(square, 7, 2), 6);

 squareSetNumber(getSquare(square, 7, 2), 3);



 UnityAssertEqualNumber((_U_SINT)((164)), (_U_SINT)((square[6][1])), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);



 removeOthersExcept(getSquare(square, 7, 2), 6);



 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((square[6][1])), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

}



void test_isSquareContain_should_return_1_for_number_match_square(void){

  int square[9][9];

  clearSquares(square);



  int value;



  squareSetNumber(getSquare(square, 4, 6), 4);



  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((square[3][5])), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);



  value = isSquareContain(getSquare(square, 4, 6), 4);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((value)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

}



void test_initRowPeers(void){



  initRowPeers(rowPeers);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((rowPeers[2][2][0].row)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][0].column)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((rowPeers[2][2][1].row)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][1].column)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][2].row)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][2].column)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((rowPeers[2][2][3].row)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][3].column)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((rowPeers[2][2][4].row)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][4].column)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((rowPeers[2][2][5].row)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][5].column)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((rowPeers[2][2][6].row)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][6].column)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((rowPeers[2][2][7].row)), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][7].column)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((rowPeers[2][2][8].row)), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][8].column)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

}



void test_initColPeers(void){



  initColPeers(columnPeers);



  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][0].row)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((columnPeers[2][2][0].column)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][1].row)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((columnPeers[2][2][1].column)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][2].row)), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][2].column)), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][3].row)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((columnPeers[2][2][3].column)), (((void *)0)), (_U_UINT)193, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][4].row)), (((void *)0)), (_U_UINT)194, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((columnPeers[2][2][4].column)), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][5].row)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((columnPeers[2][2][5].column)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][6].row)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((columnPeers[2][2][6].column)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][7].row)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((columnPeers[2][2][7].column)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][8].row)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((columnPeers[2][2][8].column)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

}



void test_getBeginningIndex(void){



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getBeginningIndex(1))), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getBeginningIndex(0))), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getBeginningIndex(2))), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getBeginningIndex(5))), (((void *)0)), (_U_UINT)211, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getBeginningIndex(4))), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getBeginningIndex(3))), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((getBeginningIndex(8))), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((getBeginningIndex(7))), (((void *)0)), (_U_UINT)215, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((getBeginningIndex(6))), (((void *)0)), (_U_UINT)216, UNITY_DISPLAY_STYLE_INT);



}



void test_initBoxPeers(void){



 initBoxPeers(boxPeers);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[2][2][0].row)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[2][2][0].column)), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[2][2][1].row)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][1].column)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[2][2][2].row)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][2].column)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][3].row)), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[2][2][3].column)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][4].row)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][4].column)), (((void *)0)), (_U_UINT)233, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][5].row)), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][5].column)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][6].row)), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[2][2][6].column)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][7].row)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][7].column)), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][8].row)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][8].column)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

}



void test_initBoxPeers_1(void){



 initBoxPeers(boxPeers);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[4][2][0].row)), (((void *)0)), (_U_UINT)248, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[4][2][0].column)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[4][2][1].row)), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[4][2][1].column)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[4][2][2].row)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[4][2][2].column)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((boxPeers[4][2][3].row)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[4][2][3].column)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((boxPeers[4][2][4].row)), (((void *)0)), (_U_UINT)256, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[4][2][4].column)), (((void *)0)), (_U_UINT)257, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((boxPeers[4][2][5].row)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[4][2][5].column)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((boxPeers[4][2][6].row)), (((void *)0)), (_U_UINT)260, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((boxPeers[4][2][6].column)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((boxPeers[4][2][7].row)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[4][2][7].column)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((boxPeers[4][2][8].row)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[4][2][8].column)), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

}



void test_squareHas_has_same_number_return_1(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff)|((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                     };



  int replyValue = squareHas(square,2,2,8);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((replyValue)), (((void *)0)), (_U_UINT)281, UNITY_DISPLAY_STYLE_INT);

}



void test_squareHas_does_not_have_same_number_return_0(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                     };



  int replyValue = squareHas(square,2,2,3);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((replyValue)), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_INT);

}



void test_squareContainOneNumbers_has_more_than_1_number_return_0(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff)|((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                     };



  int replyValue = squareContainOneNumbers(square,2,2);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((replyValue)), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT);

}



void test_squareContainOneNumbers_has_one_value_return_1(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff), ((0>0)? 1<<(0 -1) : 0x1ff),((0>0)? 1<<(0 -1) : 0x1ff)},

                     };



    int Value = squareContainOneNumbers(square,2,2);

    UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((Value)), (((void *)0)), (_U_UINT)329, UNITY_DISPLAY_STYLE_INT);

}



void test_checkBinaryValue_return_number(void){

  int returnValue;

  returnValue = checkBinaryValue(1);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(2);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)338, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(4);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(8);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(16);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)347, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(32);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(64);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)353, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(128);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)356, UNITY_DISPLAY_STYLE_INT);



  returnValue = checkBinaryValue(256);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((returnValue)), (((void *)0)), (_U_UINT)359, UNITY_DISPLAY_STYLE_INT);



}

void test_eliminateNumberFromAllPeers_asasa(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff)|((8>0)? 1<<(8 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff)},

                      {((5>0)? 1<<(5 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((2>0)? 1<<(2 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff)},

                      {((1>0)? 1<<(1 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff)|((7>0)? 1<<(7 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff)},

                      {((9>0)? 1<<(9 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff)},

                      {((6>0)? 1<<(6 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff)},

                      {((4>0)? 1<<(4 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff)},

                      {((8>0)? 1<<(8 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff)},

                      {((7>0)? 1<<(7 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff)},

                     };

  printf("THIS TEST\n");

  eliminateNumberFromAllPeers(square,1,2,8);







}



void test_duplicateSquares(void){



  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff)|((4>0)? 1<<(4 -1) : 0x1ff)|((3>0)? 1<<(3 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((2>0)? 1<<(2 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff)|((4>0)? 1<<(4 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff)|((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff)|((4>0)? 1<<(4 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff)|((3>0)? 1<<(3 -1) : 0x1ff)|((1>0)? 1<<(1 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff),((3>0)? 1<<(3 -1) : 0x1ff)},

                      {((1>0)? 1<<(1 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff)|((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},



                      {((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((8>0)? 1<<(8 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff)|((5>0)? 1<<(5 -1) : 0x1ff)|((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff)|((3>0)? 1<<(3 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},



                      {((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff)|((5>0)? 1<<(5 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((9>0)? 1<<(9 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff)|((7>0)? 1<<(7 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((1>0)? 1<<(1 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                     };



  duplicateSquares(square, dupSquares);



  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((dupSquares[0][0])), (((void *)0)), (_U_UINT)511, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((dupSquares[0][1])), (((void *)0)), (_U_UINT)512, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((dupSquares[0][2])), (((void *)0)), (_U_UINT)513, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[0][3])), (((void *)0)), (_U_UINT)514, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[0][4])), (((void *)0)), (_U_UINT)515, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((128)), (_U_SINT)((dupSquares[0][5])), (((void *)0)), (_U_UINT)516, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((256)), (_U_SINT)((dupSquares[0][6])), (((void *)0)), (_U_UINT)517, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((dupSquares[0][7])), (((void *)0)), (_U_UINT)518, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[0][8])), (((void *)0)), (_U_UINT)519, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((dupSquares[0][0])), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((dupSquares[1][0])), (((void *)0)), (_U_UINT)522, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[2][0])), (((void *)0)), (_U_UINT)523, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[3][0])), (((void *)0)), (_U_UINT)524, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((dupSquares[4][0])), (((void *)0)), (_U_UINT)525, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((128)), (_U_SINT)((dupSquares[5][0])), (((void *)0)), (_U_UINT)526, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[6][0])), (((void *)0)), (_U_UINT)527, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((256)), (_U_SINT)((dupSquares[7][0])), (((void *)0)), (_U_UINT)528, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[8][0])), (((void *)0)), (_U_UINT)529, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((dupSquares[0][4])), (((void *)0)), (_U_UINT)531, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((136)), (_U_SINT)((dupSquares[1][4])), (((void *)0)), (_U_UINT)532, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((dupSquares[2][4])), (((void *)0)), (_U_UINT)533, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((dupSquares[3][4])), (((void *)0)), (_U_UINT)534, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((dupSquares[4][4])), (((void *)0)), (_U_UINT)535, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((dupSquares[5][4])), (((void *)0)), (_U_UINT)536, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((dupSquares[6][4])), (((void *)0)), (_U_UINT)537, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((66)), (_U_SINT)((dupSquares[7][4])), (((void *)0)), (_U_UINT)538, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((dupSquares[8][4])), (((void *)0)), (_U_UINT)539, UNITY_DISPLAY_STYLE_INT);

}



void test_isSudokuSolve_return_1_all_square_contain_one_number(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff),((5>0)? 1<<(5 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((6>0)? 1<<(6 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff),((8>0)? 1<<(8 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff),((9>0)? 1<<(9 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff),((7>0)? 1<<(7 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff),((3>0)? 1<<(3 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff),((5>0)? 1<<(5 -1) : 0x1ff)},

                     };



  int value = isSudokuSolved(square);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((value)), (((void *)0)), (_U_UINT)555, UNITY_DISPLAY_STYLE_INT);

}



void test_isSudokuSolve_return_0_one_square_contain_two_number(void){

  int square[9][9] = {{((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff),((5>0)? 1<<(5 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff)|((2>0)? 1<<(2 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff),((1>0)? 1<<(1 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff),((6>0)? 1<<(6 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff),((8>0)? 1<<(8 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((9>0)? 1<<(9 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((2>0)? 1<<(2 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff),((9>0)? 1<<(9 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((4>0)? 1<<(4 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((1>0)? 1<<(1 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff),((7>0)? 1<<(7 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((8>0)? 1<<(8 -1) : 0x1ff),((3>0)? 1<<(3 -1) : 0x1ff)},

                      {((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((6>0)? 1<<(6 -1) : 0x1ff), ((3>0)? 1<<(3 -1) : 0x1ff), ((7>0)? 1<<(7 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff), ((5>0)? 1<<(5 -1) : 0x1ff),((5>0)? 1<<(5 -1) : 0x1ff)},

                     };



  int value = isSudokuSolved(square);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((value)), (((void *)0)), (_U_UINT)571, UNITY_DISPLAY_STYLE_INT);

}
