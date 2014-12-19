/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_getSquare_should_enter_column_2_row_1_and_return_2(void);
extern void test_getSquare_should_enter_column_6_row_4_and_return_7(void);
extern void test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3_2_1_4(void);
extern void test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4_2_6(void);
extern void test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2_7_8(void);
extern void test_squareDelNumber_should_enter_column_4_row_2_and_del_bit_5(void);
extern void test_squareDelNumber_should_enter_column_9_row_9_and_del_bit_6(void);
extern void test_squareDelNumber_should_enter_column_5_row_1_and_del_bit_2_4(void);
extern void test_removeOthersExcept_should_enter_column_4_row_2_and_remove_all_except_4(void);
extern void test_removeOthersExcept_should_enter_column_7_row_3_and_remove_all_except_4(void);
extern void test_isSquareContain_should_return_1_for_number_match_square(void);
extern void test_initRowPeers(void);
extern void test_initColPeers(void);
extern void test_getBeginningIndex(void);
extern void test_initBoxPeers(void);
extern void test_initBoxPeers_1(void);
extern void test_squareHas_has_same_number_return_1(void);
extern void test_squareHas_does_not_have_same_number_return_0(void);
extern void test_squareContainOneNumbers_has_more_than_1_number_return_0(void);
extern void test_squareContainOneNumbers_has_one_value_return_1(void);
extern void test_checkBinaryValue_return_number(void);
extern void test_eliminateNumberFromAllPeers_with_2_recursive(void);
extern void test_eliminateNumberFromAllPeers_with_3_recursive(void);
extern void test_eliminateNumberFromAllPeers_for_checking_row_0_column_1(void);
extern void test_duplicateSquares(void);
extern void test_isSudokuSolve_return_1_all_square_contain_one_number(void);
extern void test_isSudokuSolve_return_0_one_square_contain_two_number(void);
extern void test_selectSquareWithLeastValues_should_return_row_0(void);
extern void test_nakedPair_eliminate_row(void);
extern void test_nakedPair_eliminate_column(void);
extern void test_nakedPair_eliminate_box(void);
extern void test_nakedPair_eliminate_row_column_and_box(void);
extern void test_eliminateNakedPair_with_successful_eliminate(void);
extern void test_bruteForce_with_successful_eliminate(void);
extern void test_bruteForce_with_successful_eliminate_1(void);
extern void test_bruteForce_with_successful_eliminate_2(void);
extern void test_grids(void);
extern void test_grids_should_fail(void);
extern void test_grids_Alphabet(void);
extern void test_searchPosibilityValueOfEmptySquare_all_peers_4(void);
extern void test_nakedTriples_eliminate_row(void);
extern void test_nakedTriples_eliminate_column(void);
extern void test_nakedTriples_eliminate(void);
extern void test_nakedQuad_eliminate_row(void);
extern void test_nakedQuad_eliminate(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_Square.c";
  UnityBegin();
  RUN_TEST(test_getSquare_should_enter_column_2_row_1_and_return_2, 10);
  RUN_TEST(test_getSquare_should_enter_column_6_row_4_and_return_7, 22);
  RUN_TEST(test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3_2_1_4, 34);
  RUN_TEST(test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4_2_6, 46);
  RUN_TEST(test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2_7_8, 57);
  RUN_TEST(test_squareDelNumber_should_enter_column_4_row_2_and_del_bit_5, 68);
  RUN_TEST(test_squareDelNumber_should_enter_column_9_row_9_and_del_bit_6, 83);
  RUN_TEST(test_squareDelNumber_should_enter_column_5_row_1_and_del_bit_2_4, 98);
  RUN_TEST(test_removeOthersExcept_should_enter_column_4_row_2_and_remove_all_except_4, 114);
  RUN_TEST(test_removeOthersExcept_should_enter_column_7_row_3_and_remove_all_except_4, 129);
  RUN_TEST(test_isSquareContain_should_return_1_for_number_match_square, 144);
  RUN_TEST(test_initRowPeers, 158);
  RUN_TEST(test_initColPeers, 182);
  RUN_TEST(test_getBeginningIndex, 206);
  RUN_TEST(test_initBoxPeers, 219);
  RUN_TEST(test_initBoxPeers_1, 242);
  RUN_TEST(test_squareHas_has_same_number_return_1, 265);
  RUN_TEST(test_squareHas_does_not_have_same_number_return_0, 281);
  RUN_TEST(test_squareContainOneNumbers_has_more_than_1_number_return_0, 297);
  RUN_TEST(test_squareContainOneNumbers_has_one_value_return_1, 313);
  RUN_TEST(test_checkBinaryValue_return_number, 329);
  RUN_TEST(test_eliminateNumberFromAllPeers_with_2_recursive, 359);
  RUN_TEST(test_eliminateNumberFromAllPeers_with_3_recursive, 415);
  RUN_TEST(test_eliminateNumberFromAllPeers_for_checking_row_0_column_1, 466);
  RUN_TEST(test_duplicateSquares, 485);
  RUN_TEST(test_isSudokuSolve_return_1_all_square_contain_one_number, 534);
  RUN_TEST(test_isSudokuSolve_return_0_one_square_contain_two_number, 550);
  RUN_TEST(test_selectSquareWithLeastValues_should_return_row_0, 566);
  RUN_TEST(test_nakedPair_eliminate_row, 597);
  RUN_TEST(test_nakedPair_eliminate_column, 624);
  RUN_TEST(test_nakedPair_eliminate_box, 651);
  RUN_TEST(test_nakedPair_eliminate_row_column_and_box, 678);
  RUN_TEST(test_eliminateNakedPair_with_successful_eliminate, 705);
  RUN_TEST(test_bruteForce_with_successful_eliminate, 755);
  RUN_TEST(test_bruteForce_with_successful_eliminate_1, 804);
  RUN_TEST(test_bruteForce_with_successful_eliminate_2, 862);
  RUN_TEST(test_grids, 941);
  RUN_TEST(test_grids_should_fail, 950);
  RUN_TEST(test_grids_Alphabet, 965);
  RUN_TEST(test_searchPosibilityValueOfEmptySquare_all_peers_4, 1017);
  RUN_TEST(test_nakedTriples_eliminate_row, 1102);
  RUN_TEST(test_nakedTriples_eliminate_column, 1131);
  RUN_TEST(test_nakedTriples_eliminate, 1159);
  RUN_TEST(test_nakedQuad_eliminate_row, 1185);
  RUN_TEST(test_nakedQuad_eliminate, 1212);

  return (UnityEnd());
}
