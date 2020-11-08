#include <iostream>
#include <iterator>

using namespace std;

void modArr(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i]++;
  }
}

void costArr(int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    arr[i]++;
  }
}

void showArr(int arr[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void modByValue(int i) { i++; }

void modByRef(int &i) { i++; }

int main() {
  int arr1[] = {1, 2, 3, 4, 5, 6, 7};
  int arr2[] = {1, 2, 3, 4, 5, 6, 7};

  costArr(arr1, 8);
  modArr(arr2, 8);

  showArr(arr1, 8);
  showArr(arr2, 8);

  int i1 = 1;
  int i2 = 1;

  modByValue(i1);
  modByRef(i2);

  cout << i1 << " " << i2;

  int x = 2;
  int y = 3;
  int *p = &x;
  int *q = &y;  // now p!=q and *p!=*q
  p = q;        // p becomes &y; now p==q, so (obviously)*p == *q

  int x1 = 7;
  int &r{x1};
  r += 7;
  //    int &r2; //incorrect binding
  //    r2 = 99;
  cout << endl << x1 << endl << r;

  return 0;
}

int count_x(char *p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
  if (p == nullptr) return 0;

  // Pointer moves to the next int position (as if it was an array)
  p++;
  // Pointer moves to the next int position (as if it was an array)
  ++p;

  /* All the following three cases are same they increment the value
   * of variable that the pointer p points.
   */
  ++*p;
  ++(*p);
  ++*(p);

  int count = 0;
  while (*p) {
    if (*p == x) ++count;
    ++p;
  }
  return count;
}
