#pragma once

#include <memory>
#include <string>

class PersonBuilder;

class Person {

public:
  [[nodiscard]] std::string getId() const;

  [[nodiscard]] std::string getName() const;

  [[nodiscard]] unsigned short getAge() const;

  static PersonBuilder builder();

  friend std::ostream &operator<<(std::ostream &os, const Person &person);

  bool operator==(const Person &person) const;

  friend class PersonBuilder;

private:
  std::string id;
  std::string name;
  unsigned short age{};

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

struct PersonHash{
  size_t operator()(const Person &person) const;
};

namespace std {
template <> class hash<Person> {
public:
  size_t operator()(const Person &person) const;
};

} // namespace std
