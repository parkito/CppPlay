#include <iostream>
#include <vector>

namespace my_name {
class A {
public:
  int a;
};

void show() { std::cout << "show"; }
} // namespace my_name

namespace A {
namespace B {
void funk() {}
} // namespace B
} // namespace A

namespace C::D::E {
void funk1() {}
} // namespace C::D::E

using VectorOfVector = std::vector<std::vector<int>>;

int main() {
  my_name::show();
  A::B::funk();
  C::D::E::funk1();
  VectorOfVector v{};
  std::vector<int> vec{};
  v.push_back(vec);
}
