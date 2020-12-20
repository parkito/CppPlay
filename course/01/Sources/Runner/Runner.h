#pragma once

#include "../Common/IpCommon.h"
#include "../Filter/Filter.h"
#include "../Filter/SortedFilter.h"
#include "../Filter/FirstByteFilter.h"
#include "../Filter/FirstAndSecondByteFilter.h"
#include <AnyByteFilter.h>
#include "../Comparator/LexicographicComparator.h"
#include <memory>
#include <utility>
#include <StdReader.h>
#include <Formatter.h>

namespace ip {
    class Runner {
    public:
        Runner(std::unique_ptr<ip::IReader> &c_reader,
               std::unique_ptr<ip::Formatter> &c_formatter,
               std::unique_ptr<ip::LexicographicComparator> &c_comparator) :
                reader(std::move(c_reader)),
                formatter(std::move(c_formatter)),
                comparator(std::move(c_comparator)) {};

        ip::Output run(const std::optional<std::string> &filePath);

    private:
        const std::unique_ptr<ip::IReader> reader;
        const std::unique_ptr<ip::Formatter> formatter;
        const std::unique_ptr<ip::LexicographicComparator> comparator;

        template<typename Filter, typename ... Filters>
        std::vector<std::unique_ptr<Filter>> to_filters(Filters &&...filters);

        ip::Output merge(std::vector<ip::Output> &outputs);
    };
}

