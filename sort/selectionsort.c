/*********************************************************
 * 选择排序算法（selection sort algorichms）
 *
 * 算法思想：
 * 首先，选出数组中的最小元素，将其与数组中第一个元素进行交换。然后，
 * 找出次小的元素，并将其与数组中的第二个元素进行交换。按照这种方法一直
 * 进行下去，知道整个数组排完序。
 * 
 * 算法时间复杂度：O(N^2)
 * 选择排序算法是稳定的。
 *********************************************************/

#include <stdio.h>
#include "sortcommon.h"

void sort(Item a[], int l, int r)
{
  int i, j;

  printf("selection sort...\n");
  for (i = l; i < r; i++) {
    int min = i;
    for (j = i+1; j <= r; j++) {
      if (less(a[j], a[min])) {
	min = j;
      }
    }
    exch(a[i], a[min]);
  }
}
