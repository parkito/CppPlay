#include "iostream"

// It inspects the declared type of an entity or the type of an expression. Auto lets you declare a
// variable with particular type whereas decltype lets you extract the type from the variable so
// decltype is sort of an operator that evaluates the type of passed expression.

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B> auto findMin(A a, B b) -> decltype(auto) { return (a < b) ? a : b; }

int main() {
  int jVariable = 1;
  std::cout << typeid(jVariable).name() << std::endl;

  // This call returns 3.44 of doubale type
  std::cout << findMin(4, 3.44) << std::endl;

  // This call returns 3 of double type
  std::cout << findMin(5.4, 3) << std::endl;

  auto au = findMin(5.4, 3);
  std::cout << typeid(au).name() << " " << au;

  int i = 42;

  int arr[10];

  decltype(arr[1000]) c3 = i;

  auto f1 = decltype(1 + 3.14)(1);
}

struct car {
  int engine;

private:
  car() = delete;  // any use of this constructor is an error
};