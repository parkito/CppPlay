#include <exception>
#include <iostream>
#include <stdexcept>

double func(int *arr, int i) {
  if (arr == nullptr) {
    throw std::out_of_range{"Exception is happened"};
  }
  return arr[i];
}

// method will never throw exception
void funk1() noexcept {
  try {
    func(nullptr, 3);
    throw;
  } catch (std::out_of_range &ex) {
    std::cout << "Was caught " << ex.what();
  }
}

void badFunc() noexcept { throw std::length_error("Error"); }

int main() {
  funk1();
  badFunc();
  std::cout << std::endl << "line" << std::endl;
  func(nullptr, 3);
}

void test() {
  try {
    func(nullptr, 3);
  } catch (std::length_error &) {
    std::cerr << "test failed: length error\n";
    throw;
  } catch (std::bad_alloc &) {
    std::terminate();
  }
}
