#include <lesson/search.h>
#include <lesson/array/vector.h>

int lesson::search::linear(lesson::array::vector<int>& vec, int element) {
  for (size_t i = 0; i <= vec.end(); i++) {
    if (vec[i] == element) {
      return i;
    }
  }
  return -1;
}

int lesson::search::binary(lesson::array::vector<int>& vec, int element) {
  int lower_limit = 0;
  int upper_limit = vec.end();
  while (lower_limit <= upper_limit) {
    int middle = (lower_limit + upper_limit) / 2;
    if (vec[middle] == element) {
      return middle;
    } else if (vec[middle] > element) {
      upper_limit = middle - 1;
    } else {
      lower_limit = middle + 1;
    }
  }
  return -1;
}
