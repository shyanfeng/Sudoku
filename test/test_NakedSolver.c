#include "unity.h"
#include "Square.h"
#include "ErrorCode.h"
#include "CException.h"
#include "NakedSolver.h"

void setUp(void){}

void tearDown(void){}

void test_nakedPair(void){
    int square[9][9] =  {{C(3), C(2)|C(4), C(4), C(3), C(2), C(1), C(5), C(3),C(1)}, 
                         {C(3), C(2)|C(4), C(1), C(3), C(7), C(6), C(4), C(6),C(5)},
                         {C(3), C(2), C(5), C(3), C(7), C(6), C(4), C(3),C(1)}, 
                         {C(3), C(3), C(1), C(3), C(7), C(6), C(4), C(1),C(6)}, 
                         {C(3), C(1), C(7), C(3), C(7), C(6), C(4), C(2),C(8)}, 
                         {C(3), C(9), C(8), C(3), C(7), C(6), C(2), C(3),C(9)}, 
                         {C(3), C(8), C(4), C(3), C(7), C(6), C(1), C(5),C(7)}, 
                         {C(3), C(8), C(5), C(3), C(7), C(5), C(3), C(8),C(3)}, 
                         {C(3), C(6)|C(3), C(6), C(3), C(7), C(5), C(5), C(5),C(5)}, 
                     };

  Square *row = rowPeers[0][1];                   
  eliminateNakedPairInPeers(square,row);
  
  TEST_ASSERT_EQUAL(10,square[0][1]);
  TEST_ASSERT_EQUAL(10,square[1][1]);
  TEST_ASSERT_EQUAL(36,square[8][1]);
}