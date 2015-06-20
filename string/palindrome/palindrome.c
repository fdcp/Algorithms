/*****************************************************
 * 回文（palindrome）判断
 * 回文指一个顺着读和反着读都一样的字符串，比如madam。
 * 如何判断一个字符串是否为回文呢？
 *
 * 方法一：
 *    从字符串的两端开始向中间靠拢进行遍历并比较遇到的字符串是否相等。
 * 
 * 方法二：
 *    从字符串中间开始向两端进行遍历并比较遇到的字符是否相等。
 ****************************************************/

#include <stdlib.h>
#include <stdio.h>

//从字符串两端从向中间进行靠拢遍历
int 
isPalindromeFromTwoEnds(const char *str, int len)
{
  const char *pa, *pb;
  pa = str;
  pb = str+len-1;
  while (pa <= pb) {
    if (*pa++ != *pb--) {
      return 0;
    }
  }
  return 1;
}

//从字符串中间向两端进行遍历
int
isPalindromeFromMiddle(const char *str, int len)
{
  const char *pa, *pb;
  pa = str + (len-1)/2;
  pb = str + len/2;
  while (*pb != 0) {
    if (*pa-- != *pb++) {
      return 0;
    }
  }
  return 1;
}

//判断指定字符串是否为回文
//参数：str为要判断的字符串，len为字符串长度。
//返回值：如果字符串是回文，则返回1；否则，返回0.
int
isPalindrome(const char *str, int len)
{
  //return isPalindromeFromTwoEnds(str, len);
  return isPalindromeFromMiddle(str, len);
}

int 
main(void)
{
  printf("\"madam\" is palindrome? %d\n", isPalindrome("madam", 5));
  printf("\"madma\" is palindrome? %d\n", isPalindrome("madma", 5));
  printf("\"maam\" is palindrome? %d\n", isPalindrome("maam", 4));
  printf("\"m\" is palindrome? %d\n", isPalindrome("m", 1));
  return 0;
}
