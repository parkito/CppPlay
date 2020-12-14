#include "Runner.h"
#include <optional>

ip::Output ip::Runner::run() {
    auto input = reader->read_input(std::nullopt);
    auto formattedInput = formatter->format_input(input);

    std::vector<std::unique_ptr<Filter>> filters = to_filters<ip::Filter>(new ip::SortedFilter());
    std::vector<ip::Output> outputs{filters.size()};

    for (size_t i = 0; i < outputs.size(); ++i) {
        outputs[i] = filters[i]->filter(formattedInput);
    }

    return this->merge(outputs);
}

template<typename Filter, typename... Filters>
std::vector<std::unique_ptr<Filter>> ip::Runner::to_filters(Filters &&...filters) {
    std::vector<std::unique_ptr<Filter>> vec;
    vec.reserve(sizeof...(Filters));
    (vec.emplace_back(std::move(filters)), ...);
    return vec;
}

ip::Output ip::Runner::merge(std::vector<ip::Output> &outputs) {
    ip::Output merged;
    for (auto &el:outputs) {
        std::move(el.begin(), el.end(), std::back_inserter(merged));
    }
    return merged;
}

