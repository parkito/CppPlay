#include <iostream>
using namespace std;

std::pair<int, int> foo(int a, int b) { return std::make_pair(a + b, a - b); }

std::pair<int, int> foo1(int a, int b) { return {a + b, a - b}; }

std::pair<int, int> foo2(int a, int b) {
  std::pair<int, int> pair{1, 2};
  return pair;
}

int main() {}