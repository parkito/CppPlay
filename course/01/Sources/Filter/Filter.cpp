#include "Filter.h"

std::string ip::Filter::address_to_str(const ip::Address &address) {
    std::string res;
    for (size_t i = 0; i < address.size(); ++i) {
        if (i != 3) {
            res += (std::to_string(address[i]) + ".");
        } else {
            res += (std::to_string(address[i]));
        }
    }

    return res;
}

