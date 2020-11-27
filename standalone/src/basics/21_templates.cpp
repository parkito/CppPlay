#include <iostream>
#include <optional>
#include <tuple>
#include <vector>

template <typename T1, typename T2> decltype(auto) larger(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

template <typename T, size_t N> void tupleTemplate(std::tuple<T, size_t> tup) {
  std::cout << std::get<0>(tup) << " " << std::get<1>(tup) << " " << N << std::endl;
}

// this stuff creates a temporal variable
const auto &larger(const std::vector<int> &a, const std::vector<int> &b) { return a > b ? a : b; }
// a solution to this problem, but it return a reference to a local temporal object!
const auto &larger(const double &a, const int &b) { return a > b ? a : b; }
// the correct solution we have to evaluate the exact type
template <typename T1, typename T2> decltype(auto) correctLarge(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

template <typename T1, typename T2> decltype(auto) largerDec(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

template <typename T> std::optional<T> max(const std::vector<T> &vec) {
  if (vec.empty()) {
    return std::nullopt;
  }

  const auto *max = &vec[0];
  //  auto const *max1 = &vec[0];
  //  auto *const max2 = &vec[0];
  //  auto const *const max2 = &vec[0];
  for (auto &el : vec) {
    if (&el > max) {
      max = &el;
      //      max2 = &el; error
    }
  }

  return std::make_optional(*max);
}

int main() {
  std::vector<int> vec1 = {1, 2, 30, 4};
  std::vector<std::string> vec2 = {"aaa", "bbb", "ccc"};
  std::vector<int> vec3 = {};
  std::cout << max(vec1).value() << std::endl;
  std::cout << max(vec2).value() << std::endl;
  std::cout << max(vec3).has_value() << std::endl;

  std::tuple<std::string, size_t> tup = std::make_tuple("5R", 1);
  std::tuple<int, size_t> tup1 = std::make_tuple(5, 1);
  tupleTemplate<std::string, 3>(tup);
  tupleTemplate<int, 3>(tup1);
}