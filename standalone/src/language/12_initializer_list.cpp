#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

void show(initializer_list<int> list) {
  for (const auto &item : list) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  show({1, 2, 3});
  show({1, 1, 1, 1, 1});
}