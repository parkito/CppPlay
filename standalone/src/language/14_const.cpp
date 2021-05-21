
#include <string>
class A {
  // const methods do not allow to change class members
  void method() const {
    //    a=1;
  }
  int a;
};

// its special const that does not allow to reassignment
void method(const int *a) {
  a++;
  //  a[0] = 1;
  //  a = 1;
}

void fun(char *str) {}

int main() {
  // const make const an operator from the left or from the right if it const
  // the first member of an expression

  // pointers to const arrays
  const int *a = new int[10];
  int const *b = new int[10];

  a = new int[20]; // ok
  //  a[0] = 1; error
  //  b[0] = 1; error

  // constant pointers to array
  int *const c = new int[10];
  //  c = new int[10]; error
  c[0] = 10; // ok

  // constant pointer to to constant array
  const int *const d = new int[10];

  const char *str = "st";
  //  fun(str); //fun asks not for const
  fun(const_cast<char *>(str));//const cast
}