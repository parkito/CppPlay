#include <cstring>
#include <iostream>
#include <memory>
#include <vector>
// Before c++ 11 we didn't have a way to work with temporary object effectively
// Obj a;
// func(a)  - ok because object is names
// func(Obj()) - object is temporary and can't be used in func(Obj obj)
// Move semantic allows us to say a compiler that it can use temporary objects
// Principles
// 1) Move must NOT throw an exception
// 2) Using move - we expect that temporary object will be modified
// 3) Destructor of temporary object will be called anyway

class A {
public:
  void fun1(A &a) {}
  void fun2(const A &a) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
  void fun2(A &&a) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
  template <typename T> void fun3(T &&a) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    fun2(std::forward<T>(a));  // figures out it is temporary (goes to &&) or named (goes to &)
  };
};

int main() {
  A main;
  A a;
  A &b = a;

  main.fun1(a);
  main.fun1(b);
  //  main.fun1(A()); doesn't work because an object is temporary

  main.fun3(a);
  std::cout << "----" << std::endl;
  main.fun3(std::move(a));  // we say even an object is named - consider it as a temporary
  std::cout << "----" << std::endl;
  main.fun3(b);  // single reference to a named object main.fun2(A());  // temporary
  std::cout << "----" << std::endl;
  main.fun3(A());  // temporary
}

class Big {
  char *buffer;

public:
  Big() : buffer(new char[1000]) {
    std::cout << __PRETTY_FUNCTION__ << " // allocate 1G" << std::endl;
  }
  Big(const Big &other) : buffer(new char[1000]) {
    std::cout << __PRETTY_FUNCTION__ << " // duplicate 1G" << std::endl;
    std::memcpy(buffer, other.buffer, 1000);
  }
  Big(Big &&other) {  // temporary object is coming
    std::cout << __PRETTY_FUNCTION__ << " // steal 1G" << std::endl;
    std::swap(buffer, other.buffer);  // we swaped buffer (other is will be deleted, but we
                                      // haven't done the second allocation )
  }
  ~Big() {
    std::cout << __PRETTY_FUNCTION__ << " // destroy 1G" << std::endl;
    delete[] buffer;
  }
  Big &operator=(const Big &other) {  // named object, we just copy
    std::cout << __PRETTY_FUNCTION__ << " // duplicate 1G" << std::endl;
    std::memcpy(buffer, other.buffer, 1000);
    return *this;
  }
  Big &operator=(Big &&other) {
    std::cout << __PRETTY_FUNCTION__ << " // steal 1G" << std::endl;
    std::swap(buffer, other.buffer);
    // swap is just
    // buffer = other.buffer
    // other.buffer = nullptr
    return *this;
  }
};