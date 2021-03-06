#include "Runner.h"
#include <optional>

ip::Output ip::Runner::run(const std::optional<std::string> &filePath) {
    auto input = reader->read_input(filePath);
    auto formattedInput = formatter->format_input(input);
    auto sortedInput = comparator->sort(formattedInput);

    std::vector<std::unique_ptr<Filter>> filters = to_filters<ip::Filter>(
            new ip::SortedFilter(),
            new ip::FirstByteFilter(),
            new ip::FirstAndSecondByteFilter(),
            new ip::AnyByteFilter()
    );
    std::vector<ip::Output> outputs{filters.size()};

    for (size_t i = 0; i < outputs.size(); ++i) {
        outputs[i] = filters[i]->filter(sortedInput);
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

