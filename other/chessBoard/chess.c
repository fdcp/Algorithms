#include "chess.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cbRow=0, cbCol=0;
int *chessBoard=NULL;

/*
 * create chess board by data array
 */
void
vCreateChessBoard(int rowNum, int colNum, int *data) {
  if (rowNum <= 0 || colNum <= 0 || data == NULL) {
    return;
  }
  
  cbRow = rowNum;
  cbCol = colNum;
  chessBoard = (int *)malloc(sizeof(int) * rowNum * colNum);
  
  int i;
  for (i = 0; i < rowNum * colNum; i++) {
    chessBoard[i] = data[i];
  }
}

/*
 * print chess board
 */
void
printChessBoard() {
  int i, j;
  printf("Chess Board: \n");
  for (i = 0; i < cbRow; i++) {
    for (j = 0; j < cbCol; j++) {
      printf("%5d", chessBoard[i*cbCol + j]);
    }
    printf("\n");
  }
  printf("\n");
}


#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#define CLOCKWISE 0
#define ANTICLOCKWISE 1

struct node {
  int pointX;
  int pointY;
  int direction[4];
  int currentDirect;
  int angle;
  struct node *next;
};

/*
 * check whether point(x1, y1) and point(x2, y2) can remove.
 * if the two points can't remove, then return zero; otherwise, return non-zero.
 */
int
bCanRemove(int x1, int y1, int x2, int y2) {
  if (cbRow <= 0 || cbCol <= 0 || chessBoard == NULL) {
    return 1;
  }

  if (x1 < 0 || x1 >= cbRow || y1 < 0 || y1 >= cbCol) {
    return 1;
  }
  if (x2 < 0 || x2 >= cbRow || y2 < 0 || y2 >= cbCol) {
    return 1;
  }
  
  if (x1 == x2 && y1 == y2) {
    return 1;
  }

  if (chessBoard[x1 * cbCol + y1] == 0 || 
      chessBoard[x2 * cbCol + y2] == 0 ||
      chessBoard[x1 * cbCol + y1] != chessBoard[x2 * cbCol + y2]) {
    return 1;
  }

  struct node *stack = NULL;
  int angle = 0;
  int currentDir = 0;
  int roll = CLOCKWISE;

  if (y1 == y2) {
    currentDir = x1 < x2 ? DOWN : UP;
  } else if (x1 == x2) {
    currentDir = y1 < y2 ? RIGHT : LEFT;
  } else if (x1 < x2) {
    currentDir = RIGHT;
    roll = y1 < y2 ? CLOCKWISE : ANTICLOCKWISE;
  } else {
    currentDir = LEFT;
    roll = y1 < y2 ? ANTICLOCKWISE : CLOCKWISE;
  }

  printf("start, direction: %d, roll: %d\n", currentDir, roll);

  stack = (struct node *)malloc(sizeof(struct node));
  if (stack == NULL) {
    printf("malloc error\n");
    exit(-1);
  }
  memset(stack, 0, sizeof(struct node));
  stack->pointX = x1;
  stack->pointY = y1;
  stack->angle = 0;
  stack->direction[currentDir] = 1;
  stack->currentDirect = currentDir;
  stack->next = NULL;
  
  printf("start point:(%d, %d), end point:(%d, %d)\n", x1, y1, x2, y2);
  int stepX = x1, stepY = y1;
  do {
    switch (currentDir) {
    case UP:
      stepX -= 1;
      break;
    case DOWN:
      stepX += 1;
      break;
    case LEFT:
      stepY -= 1;
      break;
    case RIGHT:
    default:
      stepY += 1;
      break;
    }
    
    if (stepX == x2 && stepY == y2) {
      printf("Congratulation! arrive at point(%d, %d)\n", x2, y2);
      break;
    } else if (stepX >= 0 && stepX < cbRow
	       && stepY >= 0 && stepY < cbCol
	       && chessBoard[stepX * cbCol + stepY] == 0) {
      struct node *tmpNode = (struct node *)malloc(sizeof(struct node));
      if (tmpNode == NULL) {
	printf("malloc error\n");
	exit(-1);
      }
      memset(tmpNode, 0, sizeof(struct node));
      tmpNode->pointX = stepX;
      tmpNode->pointY = stepY;
      tmpNode->direction[currentDir] = 1; //marks the current direction
      tmpNode->direction[(currentDir+2)%4] = 1; //marks the anti direction
      tmpNode->currentDirect = currentDir;
      tmpNode->angle = angle;
      tmpNode->next = stack;
      stack = tmpNode;
      printf("step into point(%d, %d), direction: %d\n", 
	     stepX, stepY, currentDir);
    } else {
      int canTurnAround = 0;
      while (stack != NULL && 
	     (canTurnAround = turnAround(stack, roll)) == 0) {
	struct node *top = stack; //pull stack
	stack = stack->next;
	free(top);

	if (stack != NULL) {
	  printf("back to point(%d, %d)\n", stack->pointX, stack->pointY);
	}
      }
      if (canTurnAround == 1) {
	stepX = stack->pointX;
	stepY = stack->pointY;
	currentDir = stack->currentDirect;
	angle = stack->angle + 1;
	printf("turn around, current direction:%d, angle: %d\n", currentDir, angle);
      }
    }
  } while (stack != NULL);

  int step = 0;
  while (stack != NULL) {
    step += 1;
    printf("<-- (%d, %d) ", stack->pointX, stack->pointY);
    struct node *tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  printf("step:%d\n", step);

  return step;
}

/*
 * if can turn around, return 1; otherwise return 0
 */
int
turnAround(struct node *stackNode, int roll) {
  int canTurnAround = 0;
  if (stackNode->angle < 2) {
    int count = 0;
    int nextDirect = stackNode->currentDirect;
    while (count < 4) {
      nextDirect = (roll == CLOCKWISE) ?
	(nextDirect + 4 - 1) % 4 :
	(nextDirect + 1) % 4;
      if (stackNode->direction[nextDirect] != 1) {
	stackNode->direction[nextDirect] = 1;
	stackNode->currentDirect = nextDirect;
	canTurnAround = 1;
	break;
      }
      count++;
    }
  }
  return canTurnAround;
}
