#pragma once

#include "IpCommon.h"
#include "Filter.h"

namespace ip {
    class Runner {
    public:
        ip::Output &run();

    private:
        static std::vector<ip::Filter> to_filters(ip::Filter const &filters...);
    };
}

