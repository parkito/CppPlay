#include <Person.h>
#include <iostream>

int main() {
  auto person1 =
      Person::builder().withId("id1").withName("name1").withAge(10).build();

  std::cout << person1->getId() << std::endl;

  auto person2 = Person::builder().withId("id1").withAge(10).build();

  std::cout << person2->getName() << person2->getName().empty();
}