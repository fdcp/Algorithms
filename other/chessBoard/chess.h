/*
 * create chess board by data array
 */
void vCreateChessBoard(int rowNum, int colNum, int *data);

/*
 * print chess board
 */
void printChessBoard();

/*
 * check whether point(x1, y1) and point(x2, y2) can remove.
 * if the two points can't remove, then return zero; otherwise, return non-zero.
 */
int bCanRemove(int x1, int y1, int x2, int y2);
