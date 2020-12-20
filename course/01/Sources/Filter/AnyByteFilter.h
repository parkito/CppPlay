#pragma once

#include "Filter.h"

namespace ip {
    class AnyByteFilter : public ip::Filter {
    public:
        ip::Output filter(const ip::Data &data) override;
    };
}