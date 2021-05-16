#include "PersonBuilder.h"
#include <iostream>

int main() {
  auto person1 =
      PersonBuilder().withId("id1")->withName("name1")->withAge(10)->build();

  std::cout << person1->getId();
}