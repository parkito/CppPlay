#pragma onceonce

#include <array>
#include <enum.h>
#include <iostream>
#include <memory>
#include <vector>

BETTER_ENUM(Diary, int, milk, cheese, sourCream, jougurt);

BETTER_ENUM(Meat, int, chicken, pork, beef, soya);

BETTER_ENUM(Veggie, int, tomatos, pineapple, paper, lettuce);

BETTER_ENUM(PizzaType, int, norishing, vegeterian, vegan, noDiary, bird, moo);

BETTER_ENUM(Size, int, small, normal, big, large);

class AbstractPizza;

class PizzaFactory {
public:
  static std::unique_ptr<AbstractPizza> prepare(Size size, PizzaType type);
};

class AbstractPizza {
public:
  [[nodiscard]] int getSize() const;

  std::vector<Diary> &getDiary();

  std::vector<Meat> &getMeat();

  std::vector<Veggie> &getVeggie();

  virtual void cook() = 0;

  friend PizzaFactory;

private:
  int size;
  std::vector<Diary> diary;
  std::vector<Meat> meat;
  std::vector<Veggie> veggie;

  void addDiary(Diary c_diary);

  void addMeat(Meat c_meat);

  void addVeggie(Veggie c_veggie);
};

template <typename T>
void printComponent(std::vector<T> vec, const std::string &name) {
  std::cout << name + "[";
  for (const auto &item : vec) {
    std::cout << item << " ";
  }
  std::cout << "]" << std::endl;
}

void printComponents(AbstractPizza &pizza) {
  printComponent(pizza.getDiary(), "Diary");
  printComponent(pizza.getMeat(), "Meat");
  printComponent(pizza.getVeggie(), "Veggies");
}