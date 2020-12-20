#include "SortedFilter.h"

ip::Output ip::SortedFilter::filter(const ip::Data &data) {
    return to_output(data);
}
