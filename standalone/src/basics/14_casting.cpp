// static_cast can be used to convert between pointers
// to related classes (up or down the inheritance hierarchy).
// It can also perform implicit conversions.
// static_cast doesn't’t perform any checks
// static_cast won’t let you convert between two unrelated classes

// dynamic_cast is related to static_cast in the sense it helps to cast through inheritance,
// but it’s more powerful than static_cast but has an overhead.
// dynamic_cast performs a check.
// It returns nullptr if you’re trying to convert pointers
// or throws std::bad_cast if you’re trying to convert references
// But remember, this check happens in runtime, and not compile time.
// It requires the Run-Time Type Information (RTTI)
// to keep track of dynamic types and thus has a slight overhead

// const_cast is the only cast that can be used to add const to a type or take const out of a type.
// This is useful when, say you want to pass a non
// const argument to a function which expects const arguments.

// reinterpret_cast is the most dangerous cast and should be used with care.
// Do not use it if you don’t know what you’re doing.
// This cast converts any type of pointer to any other type of pointer,
// even unrelated types. No checks are performed.
// It simply copies the binary data from one pointer to another

//(type) object; // c-style cast
// type(object); // function-style cast
//
// These two are functionally equivalent and perform the followings in that order until one succeeds
//
// const_cast
// static_cast (ignoring access restrictions)
// static_cast , then const_cast
// reinterpret_cast
// reinterpret_cast, then const_cast

// It’s better not to use these two because of the fact that they can invoke reinterpret_cast,
// unless you’re 100% sure static_cast will succeed. Even then, it’s better to explicitly use
// static_cast

#include <iostream>
class Mammal {
public:
  virtual void scream() {}
};
class Human : public Mammal {
public:
  void scream() override { std::cout << "MOM" << std::endl; }
};

void f(int &x) { x = 5; }

int main() {
  Human *h = new Human;  // Pointer to object of derived type
  // cast it to pointer to base type. static_cast here is unnecessary
  Mammal *m = static_cast<Mammal *>(h);
  Mammal *m2 = static_cast<Human *>(m);  // cast back to pointer to derived type

  Human *h1 = new Human;                    // Pointer to object of derived type
  Mammal *m1 = dynamic_cast<Mammal *>(h1);  // ok
                                            //  Human *h2 = dynamic_cast<Human *>(m1);    // Error

  Mammal *m3 = new Mammal;
  Human *h3 = dynamic_cast<Human *>(m3);
  if (h3 == nullptr)
    std::cout << "Oops! Cast failed!" << std::endl;
  else
    h3->scream();

  int i = 4;         // non const variable
  const int &j = i;  // const reference

  //  f(j); error

  f(const_cast<int &>(j));

  const int i1 = 3;  // j is declared const
  int *p = const_cast<int *>(&i1);
  *p = 4;  // undefined behavior

  reinterpret_cast<unsigned int &>(i) = 42;
  std::cout << i << '\n';
  return 0;
}