#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n) {
  if (n == 0)
    return 0;
  size_t res = 1;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (array[i] <= array[i-1]) {
      if (res < count)
	res = count;
      count = 1;
    }
    else count++;
  }
  if (res < count)
    res = count;
  return res;
}
