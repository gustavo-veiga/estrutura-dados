#include "search.h"
#include "vector.h"

int lesson::search::linear(lesson::vector& vec, int element) {
  for (int i = 0; i <= vec.end(); i++) {
    if (vec.get(i) == element) {
      return i;
    }
  }
  return -1;
}

int lesson::search::binary(lesson::vector& vec, int element) {
  int lower_limit = 0;
  int upper_limit = vec.end();
  while (lower_limit <= upper_limit) {
    int middle = (lower_limit + upper_limit) / 2;
    if (vec.get(middle) == element) {
      return middle;
    } else if (vec.get(middle) > element) {
      upper_limit = middle - 1;
    } else {
      lower_limit = middle + 1;
    }
  }
  return -1;
}
