#include <stdio.h>
#include "Square.h"
#include "ErrorCode.h"
#include "CException.h"
#include "NakedSolver.h"

void eliminateNakedPairInPeers(int square[9][9],Square *peers){
   int i,y;
   int j = 0;
   int conv = 0b00000001;
   int *tempPtr1;
   int temp1;
   int yao;
   int creep; 
   for(i=0;i<9;i++){
    if(squareContainTwoNumbers(square,peers[i].row+1,peers[i].column+1) == 1){
        int *tempPtr = getSquare(square,peers[i].row+1,peers[i].column+1);
        int temp = *tempPtr;
        for(y=i+1;y<9;y++){
          if(squareContainTwoNumbers(square,peers[y].row+1,peers[y].column+1) == 1){
            tempPtr1 = getSquare(square,peers[y].row+1,peers[y].column+1);
            temp1 = *tempPtr1;
            if(temp == temp1){
              for(j=0;j<9;j++){
                yao = temp1 &(conv<<j);
                if(yao != 0){
                  creep = checkBinaryValue(yao);
                  squareSetNumber(tempPtr1,creep);
                }
              }
            }else{
              int val = temp & temp1;
              if(val == 0){
                for(j=0;j<9;j++){
                  yao = temp1 &(conv<<j);
                  if(yao != 0){
                    creep = checkBinaryValue(yao);
                    squareSetNumber(tempPtr1,creep);
                  }
                }
              }else{
                
              }
            }
          }
       }
    }
   }
}