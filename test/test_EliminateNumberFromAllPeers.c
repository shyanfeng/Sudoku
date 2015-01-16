#include "unity.h"
#include <stdio.h>
#include "mock_EliminateNumberFromAllPeers.h"
#include "Square.h"

void setUp(void){
  initRowPeers(rowPeers);
  initColPeers(columnPeers);
  initBoxPeers(boxPeers);
}

void tearDown(void){}

void test_EliminateNumberFrommAllPeers_for_mock_sudoku1_1(void){
  char read[81] = "4..27.6..798156234.2.84...7237468951849531726561792843.82.15479.7..243....4.87..2";
  int square[9][9];
  clearSquares(square);
  grids(read, square);  
  searchPossibilityValueOfEmptySquare(square);
  dumpSquare(square);
  
  _eliminateNumberFromAllPeers_Expect(square, 9, 2, 5);
  
  eliminateNumberFromAllPeers(square, 1, 2, 5);
}

void test_EliminateNumberFrommAllPeers_for_mock_sudoku1_2(void){
  char read[81] = "41.27.6..798156234.2.84...7237468951849531726561792843.82.15479.7..243....4.87..2";
  int square[9][9];
  clearSquares(square);
  grids(read, square);  
  searchPossibilityValueOfEmptySquare(square);
  dumpSquare(square);
  
  _eliminateNumberFromAllPeers_Expect(square, 3, 3, 5);
  _eliminateNumberFromAllPeers_Expect(square, 1, 6, 9);
  
  eliminateNumberFromAllPeers(square, 1, 3, 5);
}

void test_EliminateNumberFrommAllPeers_for_mock_sudoku2_1(void){
  char read[81] = "6.....8.3.4.7.................5.4.7.3..2.....1.6.......2.....5.....8.6......1....";
  int square[9][9];
  clearSquares(square);
  grids(read, square);  
  searchPossibilityValueOfEmptySquare(square);
  dumpSquare(square);
  
  eliminateNumberFromAllPeers(square, 4, 2, 9);
  
}

void test_EliminateNumberFrommAllPeers_for_mock_sudoku2_2(void){
  char read[81] = "6.....8.3.4.7...............8.5.4.7.3..2.....1.6.......2.....5.....8.6......1....";
  int square[9][9];
  clearSquares(square);
  grids(read, square);  
  searchPossibilityValueOfEmptySquare(square);
  dumpSquare(square);
  
  _eliminateNumberFromAllPeers_Expect(square, 4, 3, 9);
  
  eliminateNumberFromAllPeers(square, 4, 1, 9);
  
}
/*
void test_EliminateNumberFrommAllPeers_for_mock_sudoku2_3(void){
  char read[81] = "6.....8.3.4.7...............895.4.7.3..2.....1.6.......2.....5.....8.6......1....";
  int square[9][9];
  clearSquares(square);
  grids(read, square);  
  searchPossibilityValueOfEmptySquare(square);
  dumpSquare(square);
  
  _eliminateNumberFromAllPeers_Expect(square, 4, 3, 9);
  
  eliminateNumberFromAllPeers(square, 1, 4, 9);
  
}*/