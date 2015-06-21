/**************************************************
 * 链表翻转
 *
 * 给出一个链表和一个数K，比如链表1->2->3->4->5->6，如果k=2，
 * 则翻转后为2->1->6->5->4->3；如果k=3，则翻转后为3->2->1->
 * 6->5->4。
 *
 * 即前k个结点组成的子链表反转，剩下的子链表也反转，并将原来的末尾
 * 结点设置成原链表头结点的下一个结点。
 **************************************************/

#include <stdlib.h>
#include <stdio.h>

struct linkNode
{
  char item;
  struct linkNode *next;
};



struct linkNode *
createCharLink(const char *str)
{
  const char *p = str;
  struct linkNode *head = NULL, *curNode=NULL;
  while (*p != 0) {
    struct linkNode *tmp = malloc(sizeof(struct linkNode));
    tmp->item = *p;
    tmp->next = NULL;
    if (head == NULL) {
      curNode = tmp;
      head = curNode;
    } else {
      curNode->next = tmp;
      curNode = tmp;
    }
    ++p;
  }
  
  return head;
}

void
freeLink(struct linkNode *head)
{
  while (head != NULL) {
    struct linkNode *tmp = head;
    head = head->next;
    free(tmp);
  }
}

void
printLink(struct linkNode *head)
{
  struct linkNode *tmp=head;
  while (tmp != NULL) {
    printf("%c->", tmp->item);
    tmp = tmp->next;
  }
  printf("NIL\n");
}

//反转一个单向链表
struct linkNode *
reverseLink(struct linkNode *link)
{
  struct linkNode *cur = link;
  struct linkNode *prev = NULL;
  while (cur != NULL) {
    struct linkNode *tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;
  }
  return prev;
}

//左翻转单向链表k个结点
//返回值：翻转后的链表根结点
struct linkNode *
leftshift(struct linkNode *link, int k)
{
  if (link == NULL || k <= 0) {
    return link;
  }

  int len=0, i=k;
  struct linkNode *prev, *pcur;
  pcur = link;
  while (pcur != NULL && i > 0) {
    --i;
    ++len;
    prev = pcur;
    pcur = pcur->next;
  }

  if (i > 0) {
    i = i % len;
    prev = NULL;
    pcur = link;
    while (i > 0) {
      --i;
      prev = pcur;
      pcur = pcur->next;
    }
  }
  
  prev->next = NULL;
  prev = reverseLink(link);  //反转前半截子链表
  pcur = reverseLink(pcur);  //反转后半截子链表
  link->next = pcur;     //设置链表原先末尾结点为原头结点的下一个结点。
  return prev;
}

int 
main(int argc, char **argv)
{
  struct linkNode *link = NULL;
  int k = 0;

  if (argc != 3) {
    printf("usage: a.out <string> k\n");
    exit(-1);
  }

  k = atoi(argv[2]);

  link = createCharLink(argv[1]);
  printf("raw link is: ");
  printLink(link);
  link = leftshift(link, k);
  printf("after left shift %d nodes: ", k);
  printLink(link);
  freeLink(link);
  return 0;
}
