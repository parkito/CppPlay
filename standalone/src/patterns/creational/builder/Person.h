#pragma once

#include <string>
class Person {

public:
  const std::string &getId() const;
  const std::string &getName() const;
  unsigned short getAge() const;

private:
  std::string id;
  std::string name;
  unsigned short age;
};
