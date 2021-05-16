#include "PersonBuilder.h"

PersonBuilder::PersonBuilder() { person = std::make_unique<Person>(Person()); }

std::unique_ptr<PersonBuilder> PersonBuilder::withId(const std::string &id) {
  person->id = std::move(id);
  return std::unique_ptr<PersonBuilder>();
}
std::unique_ptr<PersonBuilder>
PersonBuilder::withName(const std::string &name) {
  return std::unique_ptr<PersonBuilder>();
}

std::unique_ptr<PersonBuilder>
PersonBuilder::withAge(const unsigned short age) {
  return std::unique_ptr<PersonBuilder>();
}

std::unique_ptr<Person> PersonBuilder::build() {
  return std::unique_ptr<Person>();
}
