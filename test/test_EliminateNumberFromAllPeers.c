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

void test_searchPosibilityValueOfEmptySquare_all_peers_to_complete_sudoku_1(void){
  char read[81] = "4..27.6..798156234.2.84...7237468951849531726561792843.82.15479.7..243....4.87..2";
  int square[9][9];
  clearSquares(square);
  grids(read, square);  
  searchPossibilityValueOfEmptySquare(square);
  dumpSquare(square);
  
   _eliminateNumberFromAllPeers_Expect(square, 9, 2, 5);
  
  eliminateNumberFromAllPeers(square, 1, 2, 5);

}

void test_searchPosibilityValueOfEmptySquare_all_peers_to_complete_sudoku_2(void){
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