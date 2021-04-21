#include <iostream>

int main() {
  char c = 'c';

  switch (c) {
  case 'a':
    std::cout << "a"; // Warning! fallthrough is perhaps a programmer error
    [[fallthrough]];  // Warning suppressed, fallthrough is ok
  case 'b':
    std::cout << "b";
    std::cout << "d";
  case 'c':
    std::cout << "c";
  }

  // help to optimize
  int a{10};
  if (a > 5) {
    [[likely]] std::cout << "yes";
  } else {
    [[unlikely]] std::cout << "yes";
  }
}
//[[nodiscard]] is used to stress that the return value of a function is not to
// be discarded, on
// pain of a compiler warning.
[[nodiscard]] int foo() { return 1; };
void bar() {
  foo(); // Warning! return value of a
  // nodiscard function is discarded
}

static void impl1() {}                  // Compilers may warn about this
[[maybe_unused]] static void impl2() {} // Warning suppressed

enum E { foobar = 0, foobat [[deprecated("message")]] = foobar };

E e = foobat; // Emits warning

namespace [[deprecated]] old_stuff {
void legacy();
}

// compilers which don't
// support MyCompilerSpecificNamespace will ignore this attribute
[[MyCompilerSpecificNamespace::do_special_thing]] void foo1();