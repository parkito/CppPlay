#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string text{"text"};
  for (size_t i{}; i < text.length(); ++i) {
    if (std::isalpha(text[i])) {
      switch (std::tolower(text[i])) {
        case 'a':
        case 'e':
        case 'u':
          break;

        default:
          break;
      }
    }
  }

  std::getline(std::cin, text, '*');

  const std::string separators{" ,;:.\"!?'\n"};
  std::vector<std::string> words;
  size_t start{text.find_first_not_of(separators)};

  while (start != std::string::npos) {
    size_t end{text.find_first_of(separators, start + 1)};
    if (end == std::string::npos) {
      end = text.length();
    }
    text.replace(start, text.length(), "replacement");   // Replace word
    words.push_back(text.substr(start, end - start));
    start = text.find_first_not_of(separators, end + 1);
  }
}