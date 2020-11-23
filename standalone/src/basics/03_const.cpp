#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
 C++ supports two notions of immutability:
 const: meaning roughly ‘I promise not to change this value.’
This is used primarily to specify interfaces
so that data can be passed to functions using pointers and references
without fear of it being modified.
The compiler enforces the promise made by const.
The value of a const can be calculated at run time.

 */

void f1(const std::string &s, std::string &s1) {
  //  s = "";  //error
  s1 = "";
}
void f2(const std::string *sptr, std::string *sptr1) {
  //  sptr->append(""); //error
  sptr1->append("");
}
void f3(std::string s) {}  // pass by value

void g1(std::string &s);

void f5(const std::string &s) {
  // g1(s);          // Compile-time Error since s is const
  std::string localCopy = s;
  g1(localCopy);  // Okay since localCopy is not const
}

class Bar {
public:
  int getBar() {
    const Bar foo = Bar();
    return foo.increment();  // OK
    // return foo.increment1();    // ERROR: non-const method be called on const variable
  }

  int foo(const int *bar) {
    // bar[0] += 4;        // ERROR: const variable cannot be modified
    return bar[0];  // OK: member variable won't be modified here
  }

  int foo1() {
    char *mybuf1 = 0, *yourbuf;
    char *const aptr = mybuf1;
    *aptr = 'a';  // OK
    // aptr = yourbuf;   // error

    const char *mybuf = "test";
    char *yourbuf1 = "test2";

    const char *bptr = mybuf;     // Pointer to constant data
    const char *bptr1 = yourbuf;  // Pointer to NOT constant data
    // *bptr = 'a';   // Error
    return 0;
  }

private:
  int value;
  int increment() const;
  int increment1();
};

// The compiler will enforce this statement by not allowing you to modify THIS
// and any of its members from within the scope of such a const qualified method
int Bar::increment() const {
  //  value++;  error
  return 0;
}

int Bar::increment1() {
  value++;
  return value;
}

/*constexpr: meaning roughly ‘to be evaluated at compile time.’
This is used primarily to specify constants,
to allow placement of data in read-only memory
(where it is unlikely to be corrupted), and for performance.
The value of a constexpr must be calculated by the compiler.
 */

double sum(const std::vector<double> &vector);

void add(double &value);

constexpr double nth(double x, int n);

int main() {
  constexpr int dmv = 17;
  //    dmv=10; incorrect
  double var = 17;
  add(var);
  cout << var;

  const double sqv = sqrt(var);
  //    add(sqv); incorrect
  //    sqv = 4; incorrect
  vector<double> v{1.2, 3.4, 4.5};

  const double s1 = sum(v);  // calculated in runtime
  //    constexpr double s2 = sum(v); //calculated by the compiler
  const double conEx = nth(1, 5);

  return 0;
}

void add(double &value) { value++; }

double sum(const vector<double> &vector) {
  double result = 0;
  for (double i : vector) {
    result += i;
  }
  return result;
}

// A constexpr function is one whose return value can be computed at compile time
// when consuming code requires it.
constexpr double nth(double x, int n) {
  double res = 1;
  int i = 0;
  while (i < n) {
    res *= x;
    ++i;
  }
  return res;
}
