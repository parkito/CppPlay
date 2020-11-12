#include "iostream"

int main() {
  std::cout << "Enter two numbers: ";
  int a, b;
  std::cin >> a >> b;

  a - b > 0 ? std::cout << a << "is greater then " << b : std::cout << b << " is bigger than " << a;
  return 0;
}
