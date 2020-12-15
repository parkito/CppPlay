#include "SortedFilter.h"

ip::Output ip::SortedFilter::filter(const ip::Data &data) {
    auto sortedData = sort(data);
    return to_output(sortedData);
}


