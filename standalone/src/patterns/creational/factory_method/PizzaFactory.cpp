#include "ItalianPizza.h"
#include "NyPizza.h"

std::unique_ptr<AbstractPizza> PizzaFactory::prepare(Size size,
                                                     PizzaType type) {
  std::unique_ptr<AbstractPizza> pizza;
  if (size._to_index() == Size::small || size._to_index() == Size::large) {
    pizza = std::make_unique<ItalianPizza>();
  } else {
    pizza = std::make_unique<NyPizza>();
  }

  switch (type) {
  case PizzaType::norishing:
    pizza->addMeat(Meat::chicken);
    pizza->addMeat(Meat::beef);
    pizza->addMeat(Meat::pork);

    pizza->addDiary(Diary::cheese);

    pizza->addVeggie(Veggie::tomatos);
    pizza->addVeggie(Veggie::pineapple);
    break;

  case PizzaType::vegeterian:
    pizza->addMeat(Meat::soya);

    pizza->addDiary(Diary::jougurt);

    pizza->addVeggie(Veggie::tomatos);
    pizza->addVeggie(Veggie::pineapple);
    pizza->addVeggie(Veggie::lettuce);
    break;

  case PizzaType::vegan:
    pizza->addMeat(Meat::soya);

    pizza->addVeggie(Veggie::tomatos);
    pizza->addVeggie(Veggie::pineapple);
    pizza->addVeggie(Veggie::lettuce);
    break;

  case PizzaType::noDiary:
    pizza->addMeat(Meat::chicken);

    pizza->addVeggie(Veggie::tomatos);
    pizza->addVeggie(Veggie::pineapple);
    pizza->addVeggie(Veggie::lettuce);
    break;

  case PizzaType::bird:
    pizza->addMeat(Meat::chicken);

    pizza->addDiary(Diary::cheese);
    pizza->addDiary(Diary::sourCream);
    pizza->addDiary(Diary::milk);

    pizza->addVeggie(Veggie::tomatos);
    pizza->addVeggie(Veggie::pineapple);
    pizza->addVeggie(Veggie::lettuce);
    break;

  case PizzaType::bird:
    pizza->addMeat(Meat::beef);

    pizza->addDiary(Diary::cheese);
    pizza->addDiary(Diary::sourCream);
    pizza->addDiary(Diary::milk);

    pizza->addVeggie(Veggie::tomatos);
    pizza->addVeggie(Veggie::lettuce);
    break;
  }

  return pizza;
}