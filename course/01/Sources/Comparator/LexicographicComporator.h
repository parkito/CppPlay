#pragma once

#include "IpCommon.h"

namespace ip {

    class LexicographicComparator {
    public:
        static ip::Data sort(ip::Data data);

    private:
        static bool compare(const ip::Address &arr1, const ip::Address &arr2);

        static bool compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index);
    };
}