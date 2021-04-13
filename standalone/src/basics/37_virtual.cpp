#include <iostream>

class A {
public:
  void funk() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  virtual void funk1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  virtual ~A() = default;
};

class B : public A {
private:
  std::string str;

public:
  B(const std::string newStr) : str(newStr){};

  void funk() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //    A::funk();
  }

  void funk1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  std::string getString() { return str; }
};

int main() {
  // virtual methods
  B b = new B("Hello");
  b.funk(); // From B

  A *ptr1 = &b;
  ptr1->funk(); // From A

  std::cout << std::endl;
  ptr1->funk1();

  // virtual destructor
  delete ptr1; // if a destructor B is not virtual - destructor of B will not be
               // called
}