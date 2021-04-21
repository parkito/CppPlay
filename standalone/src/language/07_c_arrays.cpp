#include <iostream>

void show(int *arr, size_t size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void print_size(
    const int arr[]) { // works incorrectly because sizeof shows of a reference
  std::cout << sizeof(arr) << " ";
  std::cout << sizeof(arr[0]) << " ";
  std::cout << (sizeof(arr) / sizeof(arr[0])) << std::endl;
}

void iterate(int arr[], size_t size) {
  std::cout << "iterate ";
  for (int *i = arr; i < arr + size; ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

void iterate(int *begin, const int *end) {
  for (; begin != end; ++begin) {
    std::cout << *begin << " ";
  }
  std::cout << std::endl;
}

int *max_element(int *p, int *q) {
  int *pmax = p;
  for (; p != q; ++p)
    if (*p > *pmax)
      pmax = p;
  return pmax;
}

int main() {
  int arr1[10] = {};
  show(arr1, 10);

  int arr2[] = {1, 2, 3};
  show(arr2, 3);

  int arr3[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
  show(arr3, 10);
  std::cout << (sizeof(arr3) / sizeof(arr3[0])) << std::endl;
  print_size(arr3);
  iterate(arr3, 10);
  int *a = &arr3[0];
  int *b = &arr3[5];
  iterate(a, b);
  std::cout << *max_element(a, b);
}