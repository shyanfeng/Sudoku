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



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((*valuePtr)), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}



void test_getSquare_should_enter_column_6_row_4_and_return_7(void){

 int column = 6;

 int row = 4;

 int square[9][9];

 int *valuePtr;



 square[row-1][column-1] = 7;

 valuePtr = getSquare(&square, row, column);



 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*valuePtr)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

}



void test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3_2_1_4(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 2, 1), 3);

  squareSetNumber(getSquare(&square, 2, 1), 2);

  squareSetNumber(getSquare(&square, 2, 1), 1);

  squareSetNumber(getSquare(&square, 2, 1), 4);



 UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((square[1][0])), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

}





void test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4_2_6(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 3, 8), 4);

 squareSetNumber(getSquare(&square, 3, 8), 2);

 squareSetNumber(getSquare(&square, 3, 8), 6);



 UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((square[2][7])), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

}



void test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2_7_8(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 9, 9), 2);

 squareSetNumber(getSquare(&square, 9, 9), 7);

 squareSetNumber(getSquare(&square, 9, 9), 8);



 UnityAssertEqualNumber((_U_SINT)((194)), (_U_SINT)((square[8][8])), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

}



void test_squareDelNumber_should_enter_column_4_row_2_and_del_bit_5(void){

  int square[9][9] = {0};

  squareSetNumber(getSquare(&square, 4, 2), 5);

  squareSetNumber(getSquare(&square, 4, 2), 8);

  squareSetNumber(getSquare(&square, 4, 2), 1);



  UnityAssertEqualNumber((_U_SINT)((145)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);



 squareDelNumber(getSquare(&square, 4, 2), 5);



 UnityAssertEqualNumber((_U_SINT)((129)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

}



void test_squareDelNumber_should_enter_column_9_row_9_and_del_bit_6(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 9, 9), 6);

 squareSetNumber(getSquare(&square, 9, 9), 2);

 squareSetNumber(getSquare(&square, 9, 9), 7);



 UnityAssertEqualNumber((_U_SINT)((98)), (_U_SINT)((square[8][8])), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);



 squareDelNumber(getSquare(&square, 9, 9), 6);



 UnityAssertEqualNumber((_U_SINT)((66)), (_U_SINT)((square[8][8])), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

}



void test_squareDelNumber_should_enter_column_5_row_1_and_del_bit_2_4(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 5, 1), 2);

 squareSetNumber(getSquare(&square, 5, 1), 4);

 squareSetNumber(getSquare(&square, 5, 1), 7);



 UnityAssertEqualNumber((_U_SINT)((74)), (_U_SINT)((square[4][0])), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);



 squareDelNumber(getSquare(&square, 5, 1), 2);

 squareDelNumber(getSquare(&square, 5, 1), 4);



 UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((square[4][0])), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

}



void test_removeOthersExcept_should_enter_column_4_row_2_and_remove_all_except_4(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 4, 2), 2);

 squareSetNumber(getSquare(&square, 4, 2), 4);

 squareSetNumber(getSquare(&square, 4, 2), 7);



 UnityAssertEqualNumber((_U_SINT)((74)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);



 removeOthersExcept(getSquare(&square, 4, 2), 2);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((square[3][1])), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

}



void test_removeOthersExcept_should_enter_column_7_row_3_and_remove_all_except_4(void){

 int square[9][9] = {0};

 squareSetNumber(getSquare(&square, 7, 2), 8);

 squareSetNumber(getSquare(&square, 7, 2), 6);

 squareSetNumber(getSquare(&square, 7, 2), 3);



 UnityAssertEqualNumber((_U_SINT)((164)), (_U_SINT)((square[6][1])), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);



 removeOthersExcept(getSquare(&square, 7, 2), 6);



 UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((square[6][1])), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

}



void test_isSquareContain_should_return_1_for_number_match_square(void){

  int square[9][9] = {0};

  int value;



  squareSetNumber(getSquare(&square, 4, 6), 4);



  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((square[3][5])), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);



  value = isSquareContain(getSquare(&square, 4, 6), 4);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((value)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

}



void test_initRowPeers(void){



  initRowPeers(rowPeers);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((rowPeers[2][2][0].row)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][0].column)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((rowPeers[2][2][1].row)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][1].column)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][2].row)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][2].column)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((rowPeers[2][2][3].row)), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][3].column)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((rowPeers[2][2][4].row)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][4].column)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((rowPeers[2][2][5].row)), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][5].column)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((rowPeers[2][2][6].row)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][6].column)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((rowPeers[2][2][7].row)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][7].column)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((rowPeers[2][2][8].row)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((rowPeers[2][2][8].column)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

}



void test_initColPeers(void){



  initColPeers(columnPeers);



  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][0].row)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((columnPeers[2][2][0].column)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][1].row)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((columnPeers[2][2][1].column)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][2].row)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][2].column)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][3].row)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((columnPeers[2][2][3].column)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][4].row)), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((columnPeers[2][2][4].column)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][5].row)), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((columnPeers[2][2][5].column)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][6].row)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((columnPeers[2][2][6].column)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][7].row)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((columnPeers[2][2][7].column)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((columnPeers[2][2][8].row)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((columnPeers[2][2][8].column)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

}



void test_getBeginningIndex(void){



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getBeginningIndex(1))), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getBeginningIndex(0))), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getBeginningIndex(2))), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getBeginningIndex(5))), (((void *)0)), (_U_UINT)193, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getBeginningIndex(4))), (((void *)0)), (_U_UINT)194, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getBeginningIndex(3))), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((getBeginningIndex(8))), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((getBeginningIndex(7))), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((getBeginningIndex(6))), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);



}



void test_initBoxPeers(void){



 initBoxPeers(boxPeers);



   UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][0].row)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][0].column)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][1].row)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][1].column)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][2].row)), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[2][2][2].column)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][3].row)), (((void *)0)), (_U_UINT)215, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][3].column)), (((void *)0)), (_U_UINT)216, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][4].row)), (((void *)0)), (_U_UINT)218, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][4].column)), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][5].row)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[2][2][5].column)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[2][2][6].row)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((boxPeers[2][2][6].column)), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[2][2][7].row)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((boxPeers[2][2][7].column)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[2][2][8].row)), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((boxPeers[2][2][8].column)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);





}



void test_squareHas(void){

  int square[9][9] = {0};

  square[2][2] = 1;

  squareHas(&square,1,1,1);

}
