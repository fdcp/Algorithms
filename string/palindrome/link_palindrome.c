/************************************************
 * 判断一个单向链是否为“回文”？
 * 
 * 方法：
 *   快慢指针方法，即先定位到链表中间位置，再将链表的后半逆置，
 *最后用两个指针同时从链表头部和中间开始同时遍历并比较即可。
 ***********************************************/

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

//判断一个单向链表是否为回文
//如果是，则返回1；否则，返回0.
int
isPalindrome(struct linkNode *link)
{
  int len = 0, i;
  int isPalind = 1;
  struct linkNode *pa, *pb;
  struct linkNode *prev = NULL;
  struct linkNode *middleNode = NULL;
  
  if (link == NULL) {
    return 0;
  }
  
  for (pa = link; pa != NULL; pa = pa->next) {
    len++;
  }

  if (len == 1) {
    return 1;
  }
  
  prev = NULL;
  middleNode = link;
  for (i=0; i < (len/2); i++) {
    prev = middleNode;
    middleNode = middleNode->next;
  }

  middleNode = reverseLink(middleNode);
  if (prev != NULL) {
    prev->next = middleNode;
  }
    
  pa = link;
  pb = middleNode;
  
  while (pa != middleNode) {
    if (pa->item != pb->item) {
      isPalind = 0;
      break;
    }
    pa = pa->next;
    pb = pb->next;
  }

  middleNode = reverseLink(middleNode);
  if (prev != NULL) {
    prev->next = middleNode;
  }
     
  return isPalind;
}

int 
main(int argc, char **argv)
{
  struct linkNode *link = NULL;
  int isPalind = 0;

  if (argc != 2) {
    printf("usage: a.out <string>\n");
    exit(-1);
  }

  link = createCharLink(argv[1]);
  isPalind = isPalindrome(link);
  printf("link: ");
  printLink(link);
  printf("is palindrome? %d\n", isPalind);
  freeLink(link);
  return 0;
}
