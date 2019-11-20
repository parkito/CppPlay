#include <iostream>

using namespace std;

void fun(const char *p) {
    assert(p != nullptr);
}

constexpr double C = 299792.458; // km/s

void f(double speed) {
    constexpr double local_max = 160.0 / (60 * 60);
//    static_assert(speed < C, "can't go that fast"); // error: speed must be a constant
    static_assert(local_max < C, "can't go that fast"); // OK // ...
}

int main() {
    char *p = new char[10];
    fun(p);
    fun({});
    cout << "here";
}

