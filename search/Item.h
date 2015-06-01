#ifndef ITEM_H

#define ITEM_H 0

#include <sting.h>

typedef char *Item;
typedef char *Key;
#define NULLitem NULL
#define key(A) (A)
#define eq(A, B) (strcmp(key(A), key(B)) == 0)
#define less(A, B) (strcmp(key(A), key(B)) < 0)

#endif //ITEM_H
