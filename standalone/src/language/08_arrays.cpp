#include <array>
#include <iostream>
#include <iterator>
#include <memory>

void show() {
  // construction uses aggregate initialization
  std::array<int, 3> a1{{1, 2, 3}}; // double-braces required in C++11 prior to
  // the CWG 1270 revision (not needed in C++11
  // after the revision and in C++14 and beyond)

  std::array<int, 3> a2 = {1, 2, 3}; // double braces never required after =

  std::array<std::string, 2> a3 = {std::string("a"), "b"};

  // container operations are supported
  std::sort(a1.begin(), a1.end());
  std::reverse_copy(a2.begin(), a2.end(),
                    std::ostream_iterator<int>(std::cout, " "));

  std::cout << '\n';

  // ranged for loop is supported
  for (const auto &s : a3)
    std::cout << s << ' ';

  // deduction guide for array creation (since C++17)
  std::array a4{3.0, 1.0, 4.0}; // -> std::array<double, 3>
}

void to_arr() {
  // copies a string literal
  auto a1 = std::to_array("foo");
  static_assert(a1.size() == 4);

  // deduces both element type and length
  auto a2 = std::to_array({0, 2, 1, 3});
  static_assert(std::is_same_v<decltype(a2), std::array<int, 4>>);

  // deduces length with element type specified
  // implicit conversion happens
  auto a3 = std::to_array<long>({0, 1, 3});
  static_assert(std::is_same_v<decltype(a3), std::array<long, 3>>);

  auto a4 =
      std::to_array<std::pair<int, float>>({{3, .0f}, {4, .1f}, {4, .1e23f}});
  static_assert(a4.size() == 3);

  // creates a non-copyable std::array
  auto a5 = std::to_array({std::make_unique<int>(3)});
  static_assert(a5.size() == 1);
}

int main() { show(); }