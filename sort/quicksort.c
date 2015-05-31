/*********************************************************
 * 快速排序算法（quick sort algorichms）
 *
 * 算法思想： 分治
 * 将数组划分为两部分，使其满足以下3各条件，
 *   （1）对某个i，a[i]在数组的最终位置上；
 *   （2）a[i]左边的所有元素都比a[i]小；
 *   （3）a[i]右边的所有元素都比a[i]大。
 * 然后递归地应用该方法处理两个子部分。
 * 
 * 算法时间复杂度：O(Nlog(N))
 * 插入排序算法是不稳定的。
 *********************************************************/

#include <stdio.h>
#include "sortcommon.h"

int partition(Item a[], int l, int r)
{
  int i=l-1, j = r;
  Item tmp = a[r];

  //索引i从左边开始，直到找个一个不小于tmp的元素；
  //索引j从右边开始，直到找到一个小于tmp的元素。
  //将索引i和j停止位置上的元素进行对换。
  //然后继续索引i和j继续遍历，直到两个索引相遇。
  for (;;) {
    while (less(a[++i], tmp)) { ;}
    while (less(tmp, a[--j])) {
	if (j == l) break;
    }
    if (i >= j) break;
    exch(a[i], a[j]);
  }
  exch(a[i], a[r]);
  return i;
}

void sort(Item a[], int l, int r)
{
  int vpot;
  if ( r <= l) return;
  vpot = partition(a, l, r);
  sort(a, l, vpot-1);
  sort(a, vpot+1, r);
}
