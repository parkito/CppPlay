#include <iostream>

using namespace std;

class Matrix {
public:
  Matrix operator+(Matrix y) { Matrix res; }

  Matrix *add(const Matrix &x, const Matrix &y) {  // complicated and error-prone 20th century style
    Matrix *p = new Matrix;
    return p;
    // ... for all *p[i,j], *p[i,j] = x[i,j]+y[i,j] ... return p;
  }
};

int main() {
  Matrix m1, m2;
  Matrix m3 = m1 + m2;  // no additional memory

  Matrix m4, m5;
  // ...
  Matrix *m6 = m4.add(m4, m5);  // just pointer copy
  delete m6;                    // easy to forget
}
