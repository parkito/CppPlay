#include "Filter.h"
#include <algorithm>

namespace ip {
    class SortedFilter : Filter {
    public:
        ip::Output filter(const Data &data) override {
            auto sortedData = sort(data);
            return to_output(sortedData);
        }

    private:
        ip::Data sort(ip::Data data);

        bool compare(const ip::Address &arr1, const ip::Address &arr2);

        bool compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index);
    };
}

ip::Data ip::SortedFilter::sort(ip::Data data) {
    std::sort(data.begin(), data.end(), compare);
}

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

bool ip::SortedFilter::compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index) {
    return arr1[index] < arr2[index];
}
