/*********************************************************
 * 插入排序算法（insertion sort algorichms）
 *
 * 算法思想：
 * 对列表中的所有元素从头到尾遍历一遍，将每个元素插入到该元素左边已成序
 * 子列中的正确位置。
 *
 * 算法时间复杂度：O(N^2)
 * 插入排序算法是稳定的。
 *********************************************************/

#include <stdio.h>
#include "sortcommon.h"

void sort(Item a[], int l, int r)
{
  int i;

  printf("insertion sort...\n");
  
  //将数组中的最小元素移动数组开头当作观察哨兵
  for (i = r; i > l; i--) {
    if (less(a[i], a[i-1])) {
      exch(a[i-1], a[i]);
    }
  }

  for (i = l+2; i <= r; i++) {
    int j = i;
    Item tmp = a[j];
    while (less(a[j], a[j-1])) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = tmp;
  }
}
