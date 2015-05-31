/*********************************************************
 * 希尔排序算法（shell sort algorichms）
 *
 * 算法思想：
 * 将数组重新排列，使数组中每第h个元素从任何地方开始都产生一个排好序的子数组。
 * 这种数组称为h-排序的。通过将h直到1的序列操作，即可得到排好序的数组。
 * 
 * 希尔排序是插入排序的扩展，通过允许非相邻元素进行交换来提高效率。
 *
 * 算法时间复杂度：O(N^2)
 * 插入排序算法是稳定的。
 *********************************************************/

#include <stdio.h>
#include "sortcommon.h"

void sort(Item a[], int l, int r)
{
  int i,j,h;

  printf("shell sort...\n");

  //设置最长的步数
  for (h = 1; h < (r-l)/9; h = 3*h+1)  { }

  for (; h > 0; h = h/3) {
    for (i = l+h; i <= r; i++) {
      j = i;
      Item tmp = a[i];
      while (j >= l+h && less(tmp, a[j-h])) {
	a[j] = a[j-h];
	j -= h;
      }
      a[j] = tmp;
    }
  }
}
