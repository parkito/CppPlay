#include <iostream>

using namespace std;

template <std::size_t value> void printValue() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "size_t " << value << std::endl;
}

template <const char *value> void printValue() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "Pointer = " << value << "\t value = " << *value << std::endl;
}

// non-type template parameters
template <auto value> void printMe() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << value << std::endl;
}

int main() {
  cout << "Size of char : " << sizeof(char) << " byte" << endl;
  cout << "Size of int : " << sizeof(int) << " bytes" << endl;
  cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
  cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
  cout << "Size of signed long int : " << sizeof(signed long int) << " bytes" << endl;
  cout << "Size of unsigned long int : " << sizeof(unsigned long int) << " bytes" << endl;
  cout << "Size of float : " << sizeof(float) << " bytes" << endl;
  cout << "Size of double : " << sizeof(double) << " bytes" << endl;
  cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << endl;

  static const char c = 'c';

  printValue<10>();
  printValue<&c>();

  printMe<10>();
  printMe<'a'>();

  return 0;
}