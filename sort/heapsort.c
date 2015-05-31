/****************************************************
 * 堆排序（heap sort）
 *
 * 算法思想：
 * 排序过程类似于插入排序，不过使用了堆来寻找数组中无序部分的最大元
 * 素，提高了寻找的效率。
 *
 * 算法时间复杂度：O(NlogN)
 * 归并排序算法是不稳定的。
 *****************************************************/

#include <stdio.h>
#include "sortcommon.h"

void fixDown(Item a[], int k, int N)
{
  int j;
  while (2*k <= N) {
    j = 2*k;
    if (j < N && less(a[j], a[j+1])) {
      j += 1;
    }
    
    if (!less(a[k], a[j])) break;
    exch(a[k], a[j]);
    k = j;
  }
}

void sort(Item a[], int l, int r)
{
  int k, N = r-l+1;
  Item *pq = a+l-1;
  
  printf("heap sort ... \n");
  for (k = N/2; k >= 1; k--) {
    fixDown(pq, k, N);
  }
  
  while (N > 1) {
    //将堆根节点（即当前无序部分的最大值）移到当前无序部分的最后位置。
    exch(pq[1], pq[N]);

    //对剩下的无序部分进行向下堆调整，重新获取剩下无序部分的最大值。
    fixDown(pq, 1, --N);
  }
}


