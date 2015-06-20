/****************************************************
 * 字符串左移
 *
 * 给定一个字符串，要求把字符串前面的若干各字符移动到字符串的尾部，
 * 如把字符串"abcdef"前面的2个字符"ab"移动到字符串的尾部，即
 * 变成"cdefab"。
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************
 * 方法一：
 *    循环k次，每次将字符串第一个字符移动到尾部。
 *
 * 算法时间复杂度：O(kn)，空间复杂度：O(1)
 *************************************************/
/*
char *
leftShiftOneChar(char *str)
{
  int len = strlen(str);
  if (str == NULL || len < 1) {
    return NULL;
  }
  
  char tmp = str[0];
  int i;
  for (i=1; i < len; i++) {
    str[i-1] = str[i];
  }
  str[len-1] = tmp;
  return str;
}

//对字符串str左移动k个字符
char *
leftShift(char *str, int k)
{
  while (k > 0) {
    leftShiftOneChar(str);
    --k;
  }
  return str;
}
*/

/*************************************************
 * 方法二：
 *    三步反转法。将一个字符串分成X和Y两部分，在部分字符串上
 * 定义反转操作，如XT，即X的所有字符串反转（如，X="abc"，那
 * 么XT="cba"）。那么就得到下面的结论：
 *    (XTYT)^T = YX
 * 于是，便解决了字符串移动的问题。
 *
 * 算法时间复杂度：O(n)，空间复杂度：O(1)
 ************************************************/

//对字符串str在[start, end)之间的子串进行反转操作。
void
reverse(char *str, int start, int end)
{
  if (str == NULL ||
      start >= end) {
    return;
  }

  int i,j;
  for (i=start, j=end-1; i <= j; i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}

char *
leftShift(char *str, int k)
{
  if (str == NULL || k < 1) {
    return str;
  }

  k = k % strlen(str);
  reverse(str, 0, k);
  reverse(str, k, strlen(str)); 
  reverse(str, 0, strlen(str));
  return str;
}

int
main(int argc, char **argv)
{
  if (argc != 3) {
    printf("usage: a.out <string> n\n");
    exit(-1);
  }

  int k = atoi(argv[2]);
  printf("raw string: %s\n", argv[1]);
  printf("shift count: %d\n", k);
  printf("after left shift: %s\n", leftShift(argv[1], k));
    
  return 0;
}
