#include <array>
#include <iostream>

// References are less powerful than pointers
// 1) Once a reference is created, it cannot be later made to reference another
// object; it cannot be reseated. This is often done with pointers. 2)
// References cannot be NULL. Pointers are often made NULL to indicate that they
// are not pointing to any valid thing. 3) A reference must be initialized when
// declared.

// 1) Safer: Since references must be initialized, wild references like wild
// pointers are unlikely to exist. It is still possible to have references that
// don’t refer to a valid location 2) Easier to use: References don’t need a
// dereferencing operator to access the value. They can be used like normal
// variables. ‘&’ operator is needed only at the time of declaration. Also,
// members of an object reference can be accessed with dot operator (‘.’),
// unlike pointers where arrow operator (->) is needed to access members.
// Together with the above reasons, there are few places like the copy
// constructor argument where pointer cannot be used. Reference must be used to
// pass the argument in the copy constructor. Similarly, references must be used
// for overloading some operators like ++

int fun(int &x) { return x; }

int main() {
  int a = 10;
  int b = 6;

  int *pointer = {&a};
  int &ref = {a};
  ref++;

  //  References can not be reassigned
  ref = b; // assigns 6 (the value of b) to a -- does NOT change the reference!

  std::cout << pointer << " " << *pointer << " " << ref << " " << &ref
            << " values " << a << " " << b;

  //  fun(1); error. not l value
  fun(a);

  const int &c = {a};
  //  c++; cannot modify a value using constant reference

  const int &d{5}; // const reference to rvalue is OK!

  int *e{nullptr};
  // reference to pointer. Rare but useful for reference parameters
  int *&eRef{e};
  eRef = new int[10];
  eRef[1] = 1;

  int f{10};
  int &fRef{f};
  int *fPtr = {&fRef}; // getting the address of the reference is the same as
  int *fPtr1 = {&f};   // getting address of a variable
  *fPtr = 1;

  // structural binding
  std::pair pair{"a", 1};
  auto [str, in]{pair};
  auto &[str1, in1]{pair};

  return 0;
}

class A {
public:
  A(int &a) : a(a) {}

private:
  int &a; // it ok to have changeable content here but it must be initialized in
          // the constructor
};

// Should be very careful with returning local variables. If they go out of
// scope we can get a pointer or reference to already deleted memory section

// Return by reference is typically used to return arguments passed by reference
// to the function back to the caller.
int &getElement(std::array<int, 25> &array, int index) {
  // we know that array[index] will not be destroyed when we return to the
  // caller (since the caller passed in the array in the first place!) so it's
  // okay to return it by reference
  return array[index];
}

// returning by a pointer
int *allocateArray(int size) { return new int[size]; }