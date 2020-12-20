#pragma once

#include "../Common/IpCommon.h"

namespace ip {
    class Filter {
    public:
        virtual ip::Output filter(const ip::Data &data) = 0;

    protected:
        std::string address_to_str(const ip::Address&);
    };
}


