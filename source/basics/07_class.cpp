#include <iostream>

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}

    double &operator[](int i) { return elem[i]; }

    int size() { return sz; }

private:
    double *elem; // pointer to the elements
    int sz; // the number of elements
};

int main() {
    auto vc1 = Vector(10);
    vc1[1]=1;
    std::cout << vc1[1];
}
