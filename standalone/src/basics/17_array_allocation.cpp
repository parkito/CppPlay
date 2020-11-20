#include <array>
#include <iostream>
#include <vector>

int main() {
  size_t count;
  std::cout << "How many heights will you enter? ";
  std::cin >> count;
  int height[count];  // AVL --not the best idea

  for (int i = 0; i < count; ++i) {
    height[i] = i;
    std::cout << height[i] << std::endl;
  }

  std::array<double,4> these {1.0, 2.0, 3.0, 4.0};
  std::array<double,4> those {1.0, 2.0, 3.0, 4.0};
  std::array<double,4> them  {1.0, 1.0, 5.0, 5.0};

  if (these == those) std::cout << "these and those are equal."    << std::endl;
  if (those != them)  std::cout << "those and them are not equal." << std::endl;
  if (those > them)   std::cout << "those are greater than them."  << std::endl;
  if (them < those)   std::cout << "them are less than those."     << std::endl;


  std::vector<double> x;

  x.push_back(1);
  x.push_back(2);
  x.push_back(3);

  std::cout << x.size()<<std::endl;
  std::cout << x[1];

  return 0;
}