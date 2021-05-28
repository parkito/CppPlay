#pragma once

#include "AbstractPizza.h"

class ItalianPizza : public AbstractPizza {
public:
  void cook() override;
};
