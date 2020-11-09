#include <initializer_list>
#include <iostream>
#include <stack>
#include <stdexcept>

class Vector {
public:
  Vector(std::initializer_list<double>);
  ~Vector();
  void PushBack(double);
  double pop();
  //  double Get(int);
  double operator[](int);
  int size();

private:
  double* elm;
  int lim;
  int curSize;
};

Vector::Vector(std::initializer_list<double> list)
    : elm{new double[list.size()]}, lim{static_cast<int>(list.size())} {
  curSize = list.size() - 1;
  std::copy(list.begin(), list.end(), elm);
}

Vector::~Vector() { delete[] elm; }

void Vector::PushBack(double value) {
  if (curSize + 1 <= lim) {
    elm[++curSize] = value;
  } else {
    throw std::length_error("Vector is full");
  }
}

int Vector::size() { return curSize; }

double Vector::pop() {
  if (curSize - 1 >= 0) {
    return elm[curSize--];
  } else {
    throw std::length_error("Vector is empty");
  }
}

// double Vector::Get(int index) {
double Vector::operator[](int index) {
  if (index >= 0 && index <= curSize) {
    return elm[index];
  } else {
    throw std::length_error("Incorrect index");
  }
}

int main() {
  Vector v = Vector{5.0, 6.0, 7.0};
  //  std::cout << v.Get(0) << std::endl;
  std::cout << v[0] << std::endl;
  std::cout << v[1] << std::endl;
  std::cout << v[2] << std::endl;
  //  std::cout << v.Get(10) << std::endl;
  std::cout << v.pop() << std::endl;
  v.PushBack(10.0);
  std::cout << v[2] << std::endl;
  return 0;
}