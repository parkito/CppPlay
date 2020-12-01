#pragma once

#include "Filter.h"
#include <algorithm>

namespace ip {
    class SortedFilter : public Filter {
    public:
        ip::Output filter(const Data &data) override {
            auto sortedData = sort(data);
            return to_output(sortedData);
        }

    private:
        bool compare(const ip::Address &arr1, const ip::Address &arr2);

        ip::Data sort(ip::Data data);

        bool compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index);
    };
}
