#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

int
main() {

  int data[4][4] = {
    { 1, 3, 3, 4},
    { 0, 6, 0, 0},
    { 4, 0, 2, 1},
    { 6, 0, 4, 2}
  };

  vCreateChessBoard(4, 4, (int*)data);
  printChessBoard();

  int res = bCanRemove(3, 0, 1, 1);
  printf("res: %d\n", res);
  
  return 0;
}
