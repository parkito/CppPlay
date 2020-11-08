#include <iostream>

int fun(int &x)
{
  return x;
}

int main() {
  int a = 10;
  int b = 6;

  int* pointer = &a;
  int& ref = a;
  ref++;

  //  References can not be reassigned
  ref = b;  // assigns 6 (the value of b) to a -- does NOT change the reference!

  std::cout << pointer << " " << *pointer << " " << ref << " " << &ref << " values " << a << " "
            << b;

//  fun(1); error. not l value
  fun(a);
  return 0;
}

// ref is a reference to the argument passed in, not a copy
void changeN(int& ref) { ref = 6; }


// References are less powerful than pointers
// 1) Once a reference is created, it cannot be later made to reference another object; it cannot be
// reseated. This is often done with pointers. 2) References cannot be NULL. Pointers are often made
// NULL to indicate that they are not pointing to any valid thing. 3) A reference must be initialized
// when declared.

// 1) Safer: Since references must be initialized, wild references like wild pointers are unlikely
// to exist. It is still possible to have references that don’t refer to a valid location 2) Easier
// to use: References don’t need a dereferencing operator to access the value.
// They can be used like normal variables. ‘&’ operator is needed only at the time of declaration.
// Also, members of an object reference can be accessed with dot operator (‘.’),
// unlike pointers where arrow operator (->) is needed to access members.
// Together with the above reasons, there are few places like the copy constructor argument where
// pointer
// cannot be used. Reference must be used to pass the argument in the copy constructor.
// Similarly, references must be used for overloading some operators like ++