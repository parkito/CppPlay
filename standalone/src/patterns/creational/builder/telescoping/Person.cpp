#include "Person.h"

std::string Person::getId() const { return id; }

std::string Person::getName() const { return name; }

unsigned short Person::getAge() const { return age; }

PersonBuilder Person::builder() { return PersonBuilder(); }

PersonBuilder::PersonBuilder() { person = std::make_unique<Person>(Person()); }

PersonBuilder &PersonBuilder::withId(const std::string &id) {
  person->id = id;
  return *this;
}
PersonBuilder &PersonBuilder::withName(const std::string &name) {
  person->name = name;
  return *this;
}

PersonBuilder &PersonBuilder::withAge(const unsigned short age) {
  person->age = age;
  return *this;
}

std::unique_ptr<Person> PersonBuilder::build() { return std::move(person); }
