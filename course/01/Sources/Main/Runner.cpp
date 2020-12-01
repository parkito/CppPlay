#include "Runner.h"
#include "Formatter.h"
#include "Reader.h"
#include "filter/SortedFilter.h"
#include "filter/Filter.h"

ip::Output ip::Runner::run() {
    ip::Validator validator;
    ip::Reader reader{validator};
    ip::Formatter formatter;

    auto input = reader.read_input();
    auto formattedInput = formatter.format_input(input);

    std::vector<std::unique_ptr<Filter>> filters = to_filters<ip::Filter>(new ip::SortedFilter());
    std::vector<ip::Output> outputs(4);

    for (auto &el:filters) {
        outputs.push_back(el->filter(formattedInput));
    }

    unsigned int outputSize = this->outputSize(outputs);

    return this->merge(outputs, outputSize);
}


template<typename Filter, typename... Filters>
std::vector<std::unique_ptr<Filter>> ip::Runner::to_filters(Filters &&...filters) {
    std::vector<std::unique_ptr<Filter>> vec;
    vec.reserve(sizeof...(Filters));
    (vec.emplace_back(std::move(filters)), ...);
    return vec;
}

unsigned int ip::Runner::outputSize(std::vector<Output> &outputs) {
    unsigned int size{};
    for (auto &el:outputs) {
        size += el.size();
    }
    return size;
}

ip::Output ip::Runner::merge(std::vector<ip::Output> &outputs, unsigned int &outputSize) {
    ip::Output merged{outputSize};
    for (auto &el:outputs) {
        std::move(el.begin(), el.end(), std::back_inserter(merged));
    }
    return merged;
}

