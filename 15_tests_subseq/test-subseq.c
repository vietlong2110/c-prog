#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n);

int main() {
  int test1[] = {1, 2, 3};
  if (maxSeq(test1, 3) != 3)
    return EXIT_FAILURE;
  
  int test2[] = {1, 2, -2, -1, 0};
  if (maxSeq(test2, 5) != 3)
    return EXIT_FAILURE;

  int *test3 = NULL;
  if (maxSeq(test3, 0) != 0)
    return EXIT_FAILURE;

  int test4[] = {2};
  if (maxSeq(test4, 1) != 1)
    return EXIT_FAILURE;

  int test5[] = {3, 2, 1};
  if (maxSeq(test5, 3) != 1)
    return EXIT_FAILURE;

  int test6[] = {3, 5, 2};
  if (maxSeq(test6, 3) != 2)
    return EXIT_FAILURE;

  int test7[] = {1, 1, 1, 1};
  if (maxSeq(test7, 4) != 1)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
