#include <vector>
/*constexpr: meaning roughly ‘to be evaluated at compile time.’
This is used primarily to specify constants,
to allow placement of data in read-only memory
(where it is unlikely to be corrupted), and for performance.
The value of a constexpr must be calculated by the compiler.
 */

// A constexpr function is one whose return value can be computed at compile
// time when consuming code requires it.
constexpr double nth(double x, int n) {
  double res = 1;
  int i = 0;
  while (i < n) {
    res *= x;
    ++i;
  }
  return res;
}

constexpr double sum(const std::vector<double> &vector) {
  double result = 0;
  for (double i : vector) {
    result += i;
  }
  return result;
}

int main() {
  // calculated in compile time
  const double conEx = nth(1, 5);
  const auto v1 = std::vector<double>{};
  auto v2 = std::vector<double>{};
  double s1 = sum(v1); // calculated in compile time
  double s2 = sum(v2); // calculated in runtime

  // to persuade a compiler always execute a function in compile time - use
  // consteval from c++20

  return 0;
}