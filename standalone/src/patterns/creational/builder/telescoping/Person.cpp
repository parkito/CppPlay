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

std::ostream &operator<<(std::ostream &os, const Person &person) {
  os << "Person("
     << "id=" + person.getId() << ", name=" << person.getName()
     << ", age=" << person.getAge() << ")";
  return os;
}

bool Person::operator==(const Person &person) const {
  return id == person.id && name == person.name && age == person.age;
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

size_t PersonHash::operator()(const Person &person) const {
  return std::hash<std::string>()(person.getId()) ^
         std::hash<std::string>()(person.getName()) ^
         std::hash<unsigned short>()(person.getAge());
}

size_t std::hash<Person>::operator()(const Person &person) const {
  return std::hash<std::string>()(person.getId()) ^
         std::hash<std::string>()(person.getName()) ^
         std::hash<unsigned short>()(person.getAge());
}
