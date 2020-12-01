#include "SortedFilter.h"

bool ip::SortedFilter::compare(const ip::Address &arr1, const ip::Address &arr2) {
    bool result = false;

    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            result = compare_indexed(arr1, arr2, i);
            break;
        }
    }

    return !result;
}

ip::Data ip::SortedFilter::sort(ip::Data data) {
    std::sort(data.begin(), data.end(), &SortedFilter::compare);
    return data;
}

bool ip::SortedFilter::compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index) {
    return arr1[index] < arr2[index];
}
