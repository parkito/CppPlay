// Using explicit type conversions
#include <iostream>

int main() {
  const unsigned feet_per_yard{3};
  const unsigned inches_per_foot{12};
  const unsigned inches_per_yard{feet_per_yard * inches_per_foot};

  double length{};        // Length as decimal yards
  unsigned int yards{};   // Whole yards
  unsigned int feet{};    // Whole feet
  unsigned int inches{};  // Whole inches

  std::cout << "Enter a length in yards as a decimal: ";
  std::cin >> length;

  // Get the length as yards, feet, and inches
  yards = static_cast<unsigned int>(length);
  feet = static_cast<unsigned int>((length - yards) * feet_per_yard);
  inches = static_cast<unsigned int>(length * inches_per_yard) % inches_per_foot;

  std::cout << length << " yards converts to " << yards << " yards " << feet << " feet " << inches
            << " inches." << std::endl;

  std::cout << "The range for type short is from {} to {}\n"
            << std::endl
            << std::numeric_limits<short>::min() << std::endl
            << std::numeric_limits<short>::max() << std::endl
            << "The range for type unsigned int is from {} to {}\n"
            << std::endl
            << std::numeric_limits<unsigned int>::min() << std::endl
            << std::numeric_limits<unsigned int>::max() << std::endl
            << "The range for type long is from {} to {}\n"
            << std::endl
            << std::numeric_limits<long>::min() << std::endl
            << std::numeric_limits<long>::max() << std::endl
            << "The positive range for type float is from {} to {}\n"
            << std::endl
            << std::numeric_limits<float>::min() << std::endl
            << std::numeric_limits<float>::max() << std::endl
            << "The full range for type float is from {} to {}\n"
            << std::endl
            << std::numeric_limits<float>::lowest() << std::endl
            << std::numeric_limits<float>::max() << std::endl
            << "The positive range for type double is from {} to {}\n"
            << std::endl
            << std::numeric_limits<double>::min() << std::endl
            << std::numeric_limits<double>::max() << std::endl
            << "The positive range for type long double is from {} to {}\n"
            << std::endl
            << std::numeric_limits<long double>::min() << std::endl
            << std::numeric_limits<long double>::max();
}