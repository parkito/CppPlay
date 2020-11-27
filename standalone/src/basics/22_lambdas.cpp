#include <functional>

#include "iostream"

//[ captureClause ] ( parameters ) -> returnType
//{
// statements;
//}

static bool containsNut(std::string_view str)  // static means internal linkage in this context
{
  return (str.find("nut") != std::string_view::npos);
}

// We don't know what fn will be. std::function works with regular functions and lambdas.
void repeat(int repetitions, const std::function<void(int)>& fn) {
  for (int i{0}; i < repetitions; ++i) {
    fn(i);
  }
}

void printFound() {
  constexpr std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};
  const auto found = std::find_if(arr.begin(), arr.end(), containsNut);

  if (found == arr.end()) {
    std::cout << "No nuts\n";
  } else {
    std::cout << "Found " << *found << '\n';
  }

  // Define the function right where we use it.
  const auto found1{std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
    return (str.find("nut") != std::string_view::npos);
  })};
  std::cout << found1;

  auto isEven{[](int i) { return ((i % 2) == 0); }};

  repeat(3, [](int i) { std::cout << i << '\n'; });
}

int main() {
  int x = 1000;
  auto lam1 = [y = 100.1, x /*=*/](int a, int b) /*mutable*/ -> int { return x + y + a + b; };
  auto lam2 = [y = 100, x](int a, int b) mutable { return x++ + y++ + a + b; };
  auto lam3 = [=, y = 100.1](auto a, int b) { return x + y + a + b; };

  std::cout << lam1(1, 2) << std::endl;
  std::cout << lam2(1, 2) << " " << x << std::endl;
  std::cout << lam3(1, 2) << std::endl;

  // A regular function pointer. Only works with an empty capture clause.
  double (*addNumbers1)(double, double) = {[](double a, double b) { return (a + b); }};
  std::cout << addNumbers1(4, 3) << std::endl;

  std::function addNumbers2{// note: pre-C++17, use std::function<double(double, double)> instead
                            [](double a, double b) { return (a + b); }};

  auto addNumbers3{[](double a, double b) { return (a + b); }};
};