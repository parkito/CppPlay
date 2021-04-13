//#include <iostream>
//#include <optional>  // std::optional<> is defined in the <optional> module
//#include <string>
//#include <vector>
//
//void find_words(std::vector<std::string>& words, std::string_view str, std::string_view separators);
//
//std::optional<size_t> find_last(const std::string& string, char to_find,
//                                std::optional<size_t> start_index = std::nullopt) {
//  // code below will not work for empty strings
//  if (string.empty()) return std::nullopt;  // or: 'return std::optional<size_t>{};'
//  // or: 'return {};'
//  // determine the starting index for the loop that follows:
//  size_t index{start_index.value_or(string.size() - 1)};
//
//  while (true)  // never use while (index >= 0) here, as size_t is always >= 0!
//  {
//    if (string[index] == to_find) return index;
//    if (index == 0) return std::nullopt;
//    --index;
//  }
//}
//
//int main() {
//  std::string text;  // The string to be searched
//  std::cout << "Enter some text terminated by *:\n";
//  std::getline(std::cin, text, '*');
//
//  const std::string separators{" ,;:.\"!?'\n"};  // Word delimiters
//  std::vector<std::string> words;                // Words found
//
//  find_words(words, text, separators);
//
//  const double array[]{1.5, 44.6, 13.7, 21.2, 6.7};
//  const std::vector numbers{15, 44, 13, 21, 6, 8, 5, 2};
//  const std::vector data{3.5, 5.0, 6.0, -1.2, 8.7, 6.4};
//  const std::array array_data{3.5,  5.0, 6.0,
//                              -1.2, 8.7, 6.4};  // Throwing in an std::array for good measure
//  const std::vector<std::string> names{"Charles Dickens", "Emily Bronte", "Jane Austen",
//                                       "Henry James", "Arthur Miller"};
//  std::cout << "The largest of array is " << largest(array) << std::endl;
//  std::cout << "The largest of numbers is " << largest(numbers) << std::endl;
//  std::cout << "The largest of data is " << largest(data) << std::endl;
//  std::cout << "The largest of array_data is (also) " << largest(array_data) << std::endl;
//  std::cout << "The largest of names is " << largest(names) << std::endl;
//}
//
//void find_words(vector<string>& words, string_view text, string_view separators) {
//  size_t start{text.find_first_not_of(separators)};  // First word start index
//
//  while (start != string_view::npos)  // Find the words
//  {
//    size_t end{text.find_first_of(separators, start + 1)};  // Find end of word
//    if (end == string_view::npos)                           // Found a separator?
//      end = text.length();                                  // No, so set to end of text
//
//    words.push_back(std::string{text.substr(start, end - start)});  // Store the word
//    // Or: words.emplace_back(text.substr(start, end - start));    // (in-place construction)
//    start = text.find_first_not_of(separators, end + 1);  // Find 1st character of next word
//  }
//}
//
//// Finds the largest of a span of values
//double largest(std::span<const double> data) {
//  double max{data[0]};
//  for (auto value : data)
//    if (max < value) max = value;
//  return max;
//}
//
//// Finds the largest of a vector of int values
//int largest(std::span<const int> data) {
//  int max{data[0]};
//  for (auto value : data)
//    if (max < value) max = value;
//  return max;
//}
//
//// Finds the largest of a vector of string objects
//std::string largest(std::span<const std::string> words) {
//  std::string max_word{words[0]};
//  for (const auto& word : words)
//    if (max_word < word) max_word = word;
//  return max_word;
//}