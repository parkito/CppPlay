#include "AbstractPizza.h"

int AbstractPizza::getSize() const { return size; }

std::vector<Diary> &AbstractPizza::getDiary() { return diary; }

std::vector<Meat> &AbstractPizza::getMeat() { return meat; }

std::vector<Veggie> &AbstractPizza::getVeggie() { return veggie; }

void AbstractPizza::addDiary(Diary c_diary) { diary.push_back(c_diary); }

void AbstractPizza::addMeat(Meat c_meat) { meat.push_back(c_meat); }

void AbstractPizza::addVeggie(Veggie c_veggie) {
  veggie.push_back(c_veggie); }
