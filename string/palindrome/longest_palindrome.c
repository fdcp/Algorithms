/**************************************************
 * 给定一个字符串，求它的最长回文子串的长度
 *************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
longestPalindrome(const char *str, int len)
{
  int i, j, max=0;
  if (str == NULL || len < 1) {
    return 0;
  }

  //i is the middle point of the palindrome
  for (i=0; i < len; ++i) {

    // if the length of the palindrome is odd   
    for (j=0; (i-j >= 0) && (i+j < len); ++j) {
      if (str[i-j] != str[i+j]) {
	break;
      }
      if (j*2+1 > max) {
	max = j*2+1;
      }
    }

    // if the length of the palindrome is even
    for (j=0; (i-j >= 0) && (i+j+1 < len); ++j) {
      if (str[i-j] != str[i+j+1]) {
	break;
      }
      if (j*2+2 > max) {
	max = j*2 + 2;
      }
    }
  }

  return max;
}

int
main(int argc, char **argv)
{
  if (argc != 2) {
    printf("usage: a.out <string>\n");
    exit(-1);
  }

  printf("the length of the longest palindrome substring is: %d\n",
	 longestPalindrome(argv[1], strlen(argv[1])));
  return 0;
}
