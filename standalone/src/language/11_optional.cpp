#include <complex>
#include <iostream>
#include <optional>
#include <vector>

int main() {
  // empty:
  std::optional<int> oEmpty;
  std::optional<float> oFloat = std::nullopt;

  // direct:
  std::optional<int> oInt(10);
  std::optional oIntDeduced(10); // deduction guides

  // make_optional
  auto oDouble = std::make_optional(3.0);
  auto oComplex = std::make_optional<std::complex<double>>(3.0, 4.0);

  // in_place
  std::optional<std::complex<double>> o7{std::in_place, 3.0, 4.0};

  // will call vector with direct init of {1, 2, 3}
  std::optional<std::vector<int>> oVec(std::in_place, {1, 2, 3});

  // copy/assign:
  auto oIntCopy = oInt;

  try {
    std::cout << oEmpty.value();
  } catch (std::bad_optional_access &ex) {
    std::cout << "Exception handle!";
  }
}