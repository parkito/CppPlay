#pragma once

#include "Filter.h"

class FirstByteFilter : public ip::Filter {
public:
    ip::Output filter(const ip::Data &data) override;
};