//
// Created by artyom.karnov on 5/12/21.
//

#include "PersonBuilder.h"
PersonBuilder::PersonBuilder() {}
std::unique_ptr<PersonBuilder> PersonBuilder::withId(std::string id) {
  return std::unique_ptr<PersonBuilder>();
}
std::unique_ptr<PersonBuilder> PersonBuilder::withName(std::string name) {
  return std::unique_ptr<PersonBuilder>();
}
std::unique_ptr<PersonBuilder> PersonBuilder::withAge(unsigned short age) {
  return std::unique_ptr<PersonBuilder>();
}
std::unique_ptr<Person> PersonBuilder::build() {
  return std::unique_ptr<Person>();
}
