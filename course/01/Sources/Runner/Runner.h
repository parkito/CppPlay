#pragma once

#include "../Common/IpCommon.h"
#include "../Filter/Filter.h"
#include "../Filter/SortedFilter.h"
#include <memory>
#include <utility>
#include <StdReader.h>
#include <Formatter.h>

namespace ip {
    class Runner {
    public:
        Runner(std::unique_ptr<ip::IReader> c_reader, std::unique_ptr<ip::Formatter> c_formatter) :
                reader(std::move(c_reader)), formatter(std::move(c_formatter)) {};

        ip::Output run();

    private:
        const std::unique_ptr<ip::IReader> reader;
        const std::unique_ptr<ip::Formatter> formatter;

        template<typename Filter, typename ... Filters>
        std::vector<std::unique_ptr<Filter>> to_filters(Filters &&...filters);

        ip::Output merge(std::vector<ip::Output> &outputs);
    };
}

