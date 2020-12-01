#include <iostream>
#include <memory>
#include <vector>

class A {
public:
  virtual void fun() = 0;
};

class B : public A {
public:
  void fun() override { std::cout << "A"; }
};

class C : public A {
public:
  void fun() override { std::cout << "C"; }
};

template <typename T, typename... Args> auto process(Args &&... args) {
  std::vector<std::unique_ptr<T>> vec;
  vec.reserve(sizeof...(Args));
  (vec.emplace_back(std::move(args)), ...);
  return vec;
}

int main() {
  std::unique_ptr<B> b1(new B());
  std::unique_ptr<B> b2(new B());
  std::unique_ptr<C> c1(new C());
  std::unique_ptr<C> c2(new C());

  auto vec = process<A>(b1, b2, c1, c2);

  for (auto &el : vec) {
    el->fun();
  }
}