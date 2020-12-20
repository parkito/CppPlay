#pragma once

#include "Filter.h"
#include <algorithm>

namespace ip {
    class SortedFilter : public Filter {
    public:
        ip::Output filter(const Data &data) override;
    };
}
