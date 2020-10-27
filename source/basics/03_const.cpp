#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double sum(const std::vector<double> &vector);

void add(double &value);

constexpr double nth(double x, int n);

/*
 C++ supports two notions of immutability:
 const: meaning roughly ‘I promise not to change this value.’
This is used primarily to specify interfaces
so that data can be passed to functions using pointers and references
without fear of it being modified.
The compiler enforces the promise made by const.
The value of a const can be calculated at run time.

 constexpr: meaning roughly ‘to be evaluated at compile time.’
This is used primarily to specify constants,
to allow placement of data in read-only memory
(where it is unlikely to be corrupted), and for performance.
The value of a constexpr must be calculated by the compiler.
 */

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

    const double s1 = sum(v); //calculated in runtime
//    constexpr double s2 = sum(v); //calculated by the compiler
//    constexpr double conEx = nth(1, 5);

    return 0;
}

void add(double &value) {
    value++;
}

double sum(const vector<double> &vector) {
    double result = 0;
    for (double i : vector) {
        result += i;
    }
    return result;
}

//A constexpr function is one whose return value can be computed at compile time
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
