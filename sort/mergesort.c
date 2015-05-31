/****************************************************
 * 归并排序（merge sort）
 *
 * 算法思想：
 * 给定两个已排好序的数组，通过记录下每个数组的最小元素，且当两个数组
 * 中的最小元素的较小者备移到输出数组时，进入循环，继续这一过程，直到
 * 两个数组的元素都已输出，于是便将它们组合为一个有序的数组了。
 *
 * 算法时间复杂度：O(NlogN)
 * 归并排序算法是稳定的。
 *
 * 归并排序有个重要的特性是：顺序地访问数据。于是它经常被选为在专用和
 * 高性能计算上排序的基础，因为这些环境中，顺序访问数据更快。
 *****************************************************/

#include <stdio.h>
#include "sortcommon.h"

#define MAXN 1024
Item aux[MAXN];
void merge(Item a[], int l, int m, int r)
{
  int i,j,k;
  
  for (i = m+1; i > l; i--) {
    aux[i-1] = a[i-1];
  }

  //将第二个子数组按照倒序的方式拷贝到辅助数组中是为了
  //让两个子数组的最大元素都作为观察哨兵。
  for (j = m; j < r; j++) {
    aux[r+m-j] = a[j+1];
  }
  
  for (k = l; k <= r; k++) {
    if (less(aux[j], aux[i])) {
      a[k] = aux[j--];
    } else {
      a[k] = aux[i++];
    }
  }
}

void sort(Item a[], int l, int r)
{
  int m = (r+l) / 2;
  if (r <= l) return;
  
  sort(a, l, m);
  sort(a, m+1, r);
  merge(a, l, m, r);
}

