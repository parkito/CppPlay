#include <iostream>

int main() {
  int x{5};
  std::cout << &x << '\n'; // print the memory address of variable x
  std::cout << *(&x)
            << '\n'; // print the value at the memory address of variable x

  int *iPtr2{&x};              // also valid syntax
  std::cout << iPtr2 << '\n';  // address
  std::cout << *iPtr2 << '\n'; // value
  std::cout << &iPtr2 << '\n'; // address of the pointer

  std::cout << typeid(x).name() << '\n';
  std::cout << typeid(iPtr2).name() << '\n';
}

//a type that can get only nullptr
void doSomething(std::nullptr_t ptr)
{
  std::cout << "in doSomething()\n";
}