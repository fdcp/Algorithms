#include <stdio.h>
#include <stdlib.h>
#include "sortcommon.h"

void main(int argc, char *argv[])
{
  int i, N;
  int *a;

  if (argc != 2) {
    printf("Error! Usage: <sort> <N>\n");
    exit(-1);
  }

  N = atoi(argv[1]);
  a = malloc(N * sizeof(int));
  
  printf("rand %d elements: ", N);
  for (i = 0; i < N; i++) {
    a[i] = 1000 * (1.0 * rand()/RAND_MAX);
    printf("%3d ", a[i]);
  }
  printf("\n");

  sort(a, 0, N-1);

  printf("After sort: ");
  for (i = 0; i < N; i++) printf("%3d ", a[i]);
  printf("\n");
  free(a);
}
