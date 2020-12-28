#include <iostream>
#include <memory>

struct foo {
  auto get() { return this; }
};

struct bar {
  auto get() { return std::shared_ptr<bar>{this}; }

  auto raw() { return this; }
};

// the way not to leak internal pointer¡
struct baz : std::enable_shared_from_this<baz> {
  auto get() { return shared_from_this(); }
};

int main() {
  auto f = new foo{};
  auto ff = f->get();
  delete f;

  auto b = std::make_shared<bar>();
  std::cout << b.use_count() << std::endl;
  // internal pointer leaks
  auto bb = std::shared_ptr<bar>{b->raw()};
  std::cout << b.use_count() << " " << bb.use_count() << std::endl;
  auto bbb = b->get();
  std::cout << b.use_count() << " " << bb.use_count() << " " << bbb.use_count() << std::endl;

  // isolates internal pointer
  auto z = std::make_shared<baz>();
  std::cout << z.use_count() << std::endl;
  auto zz = z->get();
  std::cout << z.use_count() << " " << zz.use_count() << std::endl;
}
