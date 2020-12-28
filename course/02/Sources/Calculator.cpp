#include "Calculator.h"

int Calculator::calculate_fa(int num) {
    if (num == 0) {
        return 1;
    }
    return num * calculate_fa(num - 1);
}


int Calculator::calculate_fi(int num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }

    return calculate_fi(num - 1) + calculate_fi(num - 2);
}
