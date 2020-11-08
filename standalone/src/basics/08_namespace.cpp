#include <iostream>

namespace my_name {
  class A {
  public:
    int a;
  };

  void show() { std::cout << "show"; }
}  // namespace my_name

int main() { my_name::show(); }
