#pragma once

#include "../Person.h"
#include <memory>
class PersonBuilder {
public:
  PersonBuilder();

  std::unique_ptr<PersonBuilder> withId(std::string id);

  std::unique_ptr<PersonBuilder> withName(std::string name);

  std::unique_ptr<PersonBuilder> withAge(unsigned short age);

  std::unique_ptr<Person> build();

private:
  std::unique_ptr<Person> person;
};
