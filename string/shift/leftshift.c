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
