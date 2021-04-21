#include <cmath>
#include <iostream>
#include <numbers>

// you cannot use the unsigned or signed modifiers with floating-point types;
// floating-point types are always signed.
// https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
int main() {
  unsigned int hex = 0x123U;
  unsigned int dec = 291U;
  unsigned int oct = 0443U;
  unsigned int bin = 0b100100011U;

  std::cout << hex << " " << dec << " " << oct << " " << bin; // 291 291 291
  std::cout << std::endl << std::numbers::e;
  std::cout << std::endl << std::numbers::pi;
  std::cout << std::endl << std::sqrt(4);
  std::cout << std::endl << -1.1 / 0;
  std::cout << std::endl << std::isinf(-1.1 / 0);
  std::cout << std::endl << 23'123'459.456;
  std::cout << std::endl << std::numeric_limits<int>::max();
  std::cout << std::endl << std::numeric_limits<int>::min();
  std::cout << std::endl << std::numeric_limits<int>::lowest();
  std::cout << std::endl << std::numeric_limits<double>::min();
  std::cout << std::endl << std::numeric_limits<double>::lowest();
}