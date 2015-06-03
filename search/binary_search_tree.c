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

/**************************************
 * 叶子节点插入
 * 新插入的数据项都在二叉树的叶子节点。
 *************************************/
/*
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
*/

/***********************************************
 * BST的根插入
 * 新插入的数据项都通过旋转的方式移到二叉树的根
 *
 * 根插入法有个优点：最近插入的数据项都在树的顶部附近。
 * 很多应用问题动态地混合了搜索操作和插入操作，这些搜索中可能引用的数据项
 * 很大比例是最近才插入的数据项。例如，在一个商业事务处理系统中，当前活动
 * 的事情可以逗留在顶部附近并可迅速处理，不需要访问原来已经遗失的事务。
 **********************************************/

//右旋转，将子树原根节点的左子节点旋转为新根节点，原根节点作为新根节点的右子节点，
//而新根节点的原右子节点作为原根节点的左子节点。
link rotR(link h)
{
  link x = h->lchild;
  h->lchild = x->rchild;
  x->rchild = h;
  return x;
}

//左旋转，将子树原根节点的右子节点旋转微新根节点，原根节点作为新跟节点的左子节点，
//而新根节点的原左子节点作为原根节点的右子节点。
link rotL(link h)
{
  link x = h->rchild;
  h->rchild = x->lchild;
  x->lchild = h;
  return x;
}

link insertT(link h, Item item)
{
  Key v = key(item);
  if (head == z) {
    return NEW(item, z, z, 1);
  }

  if (less(v, key(h->item))) {
    //将新数据项插入到左子树中，然后执行右旋转将新数据项移动到子树的根
    h->lchild = insertT(h->lchild, item);
    h = rotR(h);
  } else {
    //将新数据项插入到右子树中，然后执行左旋转将新数据项移动到子树的根
    h->rchild = insertT(h->rchild, item);
    h = rotL(h);
  }
  return h;
}

void STinsert(Item item)
{
  head = insertT(head, item);
}
