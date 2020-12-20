#include <algorithm>
#include "LexicographicComparator.h"

bool ip::LexicographicComparator::compare(const ip::Address &arr1, const ip::Address &arr2) {
    bool result = false;

    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            result = compare_indexed(arr1, arr2, i);
            break;
        }
    }

    return !result;
}

ip::Data ip::LexicographicComparator::sort(ip::Data data) {
    std::sort(data.begin(), data.end(), LexicographicComparator::compare);
    return data;
}

bool ip::LexicographicComparator::compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index) {
    return arr1[index] < arr2[index];
}