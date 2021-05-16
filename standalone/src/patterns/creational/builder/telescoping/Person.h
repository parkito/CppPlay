#pragma once

#include <memory>
#include <string>

class PersonBuilder;

class Person {

public:
  std::string getId() const;

  std::string getName() const;

  unsigned short getAge() const;

  static PersonBuilder builder();

  friend class PersonBuilder;

private:
  std::string id;
  std::string name;
  unsigned short age;

  Person() = default;
};

class PersonBuilder {
public:
  explicit PersonBuilder();

  PersonBuilder &withId(const std::string &id);

  PersonBuilder &withName(const std::string &name);

  PersonBuilder &withAge(unsigned short age);

  std::unique_ptr<Person> build();

private:
  std::unique_ptr<Person> person;
};
