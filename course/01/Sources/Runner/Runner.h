#pragma once

#include "../Common/IpCommon.h"
#include "../Filter/Filter.h"
#include "../Filter/SortedFilter.h"
#include <memory>

namespace ip {
    class Runner {
    public:
        ip::Output run();

    private:
        template<typename Filter, typename ... Filters>
        std::vector<std::unique_ptr<Filter>> to_filters(Filters &&...filters);

        ip::Output merge(std::vector<ip::Output> &outputs);
    };
}

