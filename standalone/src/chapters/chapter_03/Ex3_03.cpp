// Operations with enumerations
#include <iostream>

int main() {
  enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
  Day yesterday{Day::Monday}, today{Day::Tuesday}, tomorrow{Day::Wednesday};
  const Day poets_day{Day::Friday};

  enum class Punctuation : char { Comma = ',', Exclamation = '!', Question = '?' };
  Punctuation ch{Punctuation::Comma};

  std::cout << static_cast<int>(yesterday) << std::endl
            << static_cast<char>(ch) << static_cast<int>(poets_day) << std::endl
            << static_cast<char>(Punctuation::Exclamation) << std::endl
            << std::endl;

  today = Day::Thursday;       // Assign new ...
  ch = Punctuation::Question;  // ... enumerator values
  tomorrow = poets_day;        // Copy enumerator value

  std::cout << static_cast<int>(today) << std::endl
            << static_cast<int>(poets_day) << std::endl
            << static_cast<char>(ch);

  //   ch = tomorrow;             /* Uncomment any of these for an error */
  //   tomorrow = Friday;
  //   today = 6;
}
