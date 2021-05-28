#pragma once

#include "AbstractPizza.h"

class NyPizza : public AbstractPizza {
public:
  void cook() override;
};
