#pragma once

#include "PersonBuilder.h"
#include <string>
class Person {

public:
  std::string getId() const;
  std::string getName() const;
  unsigned short getAge() const;

  friend class PersonBuilder;

private:
  std::string id;
  std::string name;
  unsigned short age;

  Person() {}
};
