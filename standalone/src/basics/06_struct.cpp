#include <iostream>

struct Vector {
  int sz;        // number of elements
  double *elem;  // pointer to elements
};

void vector_init(Vector &v, int s) {
  v.elem = new double[s];  // allocate an array of s doubles
  v.sz = s;
}

void f(Vector v, Vector &rv, Vector *pv) {
  int i1 = v.sz;
  int i2 = rv.sz;
  int i3 = pv->sz;
  // access through name
  // access through reference // access through pointer
}

class Vector1 {
public:
  explicit Vector1(int s) : elem{new double[s]}, sz{s} {}

  double &operator[](int i) { return elem[i]; }

  int size() const { return sz; }

private:
  double *elem;  // pointer to the elements
  int sz;        // the number of elements
};

double read_and_sum(int s) {
  Vector1 v(s);                                          // make a vector of s elements
  for (int i = 0; i != v.size(); ++i) std::cin >> v[i];  // read into elements
  auto sum = 0;
  for (int i = 0; i != v.size(); ++i) sum += v[i];  // take the sum of the elements return sum;

  return sum;
}

enum Type { ptr, num };

// A union is a struct in which all members are allocated
// at the same address so that the union occupies only
// as much space as its largest member.
// Naturally, a union can hold a value for only one member at a time.

struct Entry {
  std::string name;  // string is a standard-library type
  Type t;
  Entry *p;  // use p if t==ptr
  int i;     // use i if t==num
};

void f(Entry *pe) {
  if (pe->t == num) std::cout << pe->i;
}

union Value {
  Entry *p;
  int i;
};

struct EntryOptimal {
  std::string name;
  Type t;
  Value v;  // use v.p if t==ptr; use v.i if t==num
};

void f1(EntryOptimal *pe) {
  if (pe->t == num) std::cout << pe->t;
}

void f2(Entry *pe) {
  //    if (holds_alternative<int>(pe->t)) std::cout << get<int>(pe−>v);
}

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

Traffic_light &operator++(Traffic_light &t)  // prefix increment: ++
{
  switch (t) {
    case Traffic_light::green:
      return t = Traffic_light::yellow;
    case Traffic_light::yellow:
      return t = Traffic_light::red;
    case Traffic_light::red:
      return t = Traffic_light::green;
  }
}

int main() {
  Traffic_light light = Traffic_light::green;
  ++light;
  ++light;
  std::cout << static_cast<int>(light) << std::endl;

  auto eo = EntryOptimal();
  Entry entry = Entry();
  Value v = Value();
  v.i = 4;
  v.p = &entry;

  std::cout << v.i << std::endl << v.p;
}