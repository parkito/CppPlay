#include "iostream"

int main() {
  char text[] ={'h', 'e', 'l', 'l', 'o'};
  std::cout << sizeof(text) / sizeof(char) << std::endl;
  std::cout << text[4];
  std::cout << text[5];
  std::cout << text[7];

  const int max_length = 100;  // Array size
  char text1[max_length];   // Array to hold input string

  std::cout << "Enter a line of text:" << std::endl;

  // Read a line of characters including spaces
  std::cin.getline(text1, max_length);
  return 0;
}