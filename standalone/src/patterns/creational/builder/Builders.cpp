#include <Person.h>
#include <iostream>
#include <unordered_map>

int main() {
  auto person1 =
      Person::builder().withId("id1").withName("name1").withAge(10).build();

  std::cout << person1->getId() << std::endl;

  auto person2 = Person::builder().withId("id1").build();

  std::cout << person2->getName() << person2->getName().empty()
            << person2->getAge();

  std::cout << "P " << *person1 << std::endl;

  std::unordered_map<Person, int> map;
  std::unordered_map<Person, int, PersonHash> map2;

  map[*person1] = 1;
  map[*person2] = 2;

  map2[*person1] = 3;
  map2[*person2] = 4;

  std::cout << map[*person2];
  std::cout << map2[*person1];
}