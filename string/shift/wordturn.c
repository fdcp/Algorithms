/**************************************************
 * 单词翻转
 *
 * 描述：
 *     输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，
 * 句子中的单词已空格隔开。如输入"I am a student."，则输出为
 * "student. a am I"。
 * 
 * 实现： 解析出各个单词，然后使用辅助栈对单词后入先出即可。
 **************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STACK 1024
char *stack[MAX_STACK];
int top = -1;

char *
wordturn(const char *str, int len)
{
  char *tmp, *dst;
  int i, sindex, eindex;

  if (str == NULL) {
    return NULL;
  }
  
  eindex = 0;
  while (eindex < len && str[eindex] == ' ') {
    ++eindex;
  }

  while (eindex < len) {
    sindex = eindex;
    while (eindex < len && str[eindex] != ' ') {
      ++eindex;
    }
    i = eindex - sindex;
    tmp = malloc(sizeof(char) * (i+1));
    strncpy(tmp, str+sindex, i);
    *(tmp+i) = 0;
    stack[++top] = tmp;
    
    while (eindex < len && str[eindex] == ' ') { 
      ++eindex;
    }
  }
  
  dst = malloc(sizeof(char)*(len+1));
  i = 0;
  while (top != -1) {
    tmp = stack[top--];
    strncpy(dst+i, tmp, strlen(tmp));
    i += strlen(tmp);
    if (top != -1) {
      *(dst+i) = ' ';
      ++i;
    }
    free(tmp);
  }
  *(dst+i) = 0;
  return dst;
}

int
main(int argc, char **argv)
{
  char *dst;
  
  if (argc != 2) {
    printf("usage: a.out <string>\n");
    exit(-1);
  }

  printf("raw string: %s\n", argv[1]);
  dst = wordturn(argv[1], strlen(argv[1]));
  printf("afer word turn: %s\n", dst);
  if (dst != NULL) {
    free(dst);
  }
  return 0;
}
