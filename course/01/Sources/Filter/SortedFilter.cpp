#include "SortedFilter.h"

ip::Output ip::SortedFilter::filter(const ip::Data &data) {
    ip::Output output;

    for (auto &address:data) {
        output.push_back(address_to_str(address));
    }

    return output;
}
