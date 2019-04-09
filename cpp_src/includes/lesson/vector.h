#ifndef LESSON_VECTOR_H_
#define LESSON_VECTOR_H_

namespace lesson {
class vector {
 private:
  int *data;
  int size = 0;
  int count = 0;
  void alloc(int size);
  void realloc(int size);

 public:
  bool is_sorted = false;
  vector(int size);
  ~vector();
  int end();
  int get(int index);
  int capacity();
  void add(int element);
  void set(int index, int element);
  void swap(int left, int right);
  void remove(int index);
};
}  // namespace lesson

#endif