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
extern void test_squareHas_has_same_number_return_1(void);
extern void test_squareHas_does_not_have_same_number_return_0(void);
extern void test_squareContainNumbers_has_more_than_1_number_return_0(void);
extern void test_squareContainNumbers_has_one_value_return_1(void);
extern void test_checkBinaryValue_return_number(void);
extern void test_eliminateNumberFromPeers_given_row_peers_should(void);
extern void test_eliminateNumberFromPeers_given_should(void);


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
  RUN_TEST(test_getSquare_should_enter_column_2_row_1_and_return_2, 9);
  RUN_TEST(test_getSquare_should_enter_column_6_row_4_and_return_7, 21);
  RUN_TEST(test_squareSetNumber_should_enter_column_2_row_1_and_set_bit_3_2_1_4, 33);
  RUN_TEST(test_squareSetNumber_should_enter_column_3_row_8_and_set_bit_4_2_6, 45);
  RUN_TEST(test_squareSetNumber_should_enter_column_8_row_8_and_set_bit_2_7_8, 56);
  RUN_TEST(test_squareDelNumber_should_enter_column_4_row_2_and_del_bit_5, 67);
  RUN_TEST(test_squareDelNumber_should_enter_column_9_row_9_and_del_bit_6, 82);
  RUN_TEST(test_squareDelNumber_should_enter_column_5_row_1_and_del_bit_2_4, 97);
  RUN_TEST(test_removeOthersExcept_should_enter_column_4_row_2_and_remove_all_except_4, 113);
  RUN_TEST(test_removeOthersExcept_should_enter_column_7_row_3_and_remove_all_except_4, 128);
  RUN_TEST(test_isSquareContain_should_return_1_for_number_match_square, 143);
  RUN_TEST(test_initRowPeers, 157);
  RUN_TEST(test_initColPeers, 181);
  RUN_TEST(test_getBeginningIndex, 205);
  RUN_TEST(test_initBoxPeers, 219);
  RUN_TEST(test_squareHas_has_same_number_return_1, 243);
  RUN_TEST(test_squareHas_does_not_have_same_number_return_0, 259);
  RUN_TEST(test_squareContainNumbers_has_more_than_1_number_return_0, 275);
  RUN_TEST(test_squareContainNumbers_has_one_value_return_1, 291);
  RUN_TEST(test_checkBinaryValue_return_number, 307);
  RUN_TEST(test_eliminateNumberFromPeers_given_row_peers_should, 338);
  RUN_TEST(test_eliminateNumberFromPeers_given_should, 391);

  return (UnityEnd());
}
