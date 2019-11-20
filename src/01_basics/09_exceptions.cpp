#include <iostream>
#include <exception>

double func(int *arr, int i) {
    if (arr == nullptr)
        throw std::out_of_range{"Exception is happened"};
    return arr[i];
}

void funk1() noexcept {
    try {
        func(nullptr, 3);
    } catch (std::out_of_range &ex) {
        std::cout << "Was caught " << ex.what();
    }
}

int main() {
    funk1();
    std::cout << std::endl << "line" << std::endl;
    func(nullptr, 3);
}

void test() {
    try {

    }
    catch (std::length_error &) {
        std::cerr << "test failed: length error\n";
        throw;
    }
    catch (std::bad_alloc &) {
        std::terminate();
    }
}
