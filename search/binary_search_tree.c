/**********************************************************
 * 二叉搜索树（binary search tree, BST)
 *
 * 二叉搜索树是一棵二叉树，它的每个内部节点都关联一个关键字，并具有以下性
 * 质：任意节点的关键字大于（或等于）该节点左子树中所有节点的关键字，小于
 * （或等于）该节点右子树中所有节点的关键字。
 **********************************************************/

#include <stdlib.h>
#include "Item.h"

typedef struct STnode* link;
struct STnode { Item item; link lchild; link rchild; int count; };
static link head, z;

link NEW(Item item, link lchild, link rchild, int count)
{
  link x = malloc(sizeof *x);
  x->item = item;
  x->lchild = lchild;
  x->rchild = rchild;
  x->count = count;
  return x;
}

void STinit()
{
  head = (z = NEW(NULLitem, 0, 0, 0));
}

int STcount()
{
  return head->count;
}

Item searchR(link h, Key v)
{
  Key t = key(h->item);
  if (h == z) return NULLitem;
  if (eq(v,t)) {
    return h->item;
  } else if (less(t, v)) {
    return searchR(h->rchild, v);
  } else {
    return searchR(h->lchild, v);
  }
}

Item STsearch(Key v)
{
  return searchR(head, v);
}

link insertR(link h, Item item)
{
  Key v = key(item), t = key(h->item);
  if (h == z) {
    return NEW(item, z, z, 1);
  }
  
  if (less(v, t)) {
    h->lchild = insertR(h->lchild, item);
  } else {
    h->rchild = insertR(h->rchild, item);
  }
  (h->count)++;
  return h;
}

void STinsert(Item item)
{
  head = insertR(head, item);
}
