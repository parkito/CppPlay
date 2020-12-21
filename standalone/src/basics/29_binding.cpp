#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

bool cmp(int i) {
  return i > 2;
}

bool comp(int i, int p) {
  return i > p;
}

bool comp_helper(int i) {
  return comp(i, 2);
}

int main()
{
  std::vector<int> v{0, 1, 2, 3, 4};

  auto result = std::find_if(std::begin(v), std::end(v), [](auto i){ return i > 2; });
    auto result1 = std::find_if(std::begin(v), std::end(v), [p = 2](auto i){ return i > p; });
    auto result2 = std::find_if(std::begin(v), std::end(v), cmp);
//    auto result3 = std::find_if(std::begin(v), std::end(v), comp); //can't call a method with 2 parameters
    auto result4 = std::find_if(std::begin(v), std::end(v), std::bind(comp, std::placeholders::_1, 2)); //2nd parameter in comp is always 2

  for (; result != std::end(v); ++result)
  {
    std::cout << *result << " ";
  }
  std::cout << std::endl;
}
