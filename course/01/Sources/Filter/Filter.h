#pragma once

#include "../Common/IpCommon.h"

namespace ip {
    class Filter {
    public:
        virtual ip::Output filter(const ip::Data &data) = 0;

    protected:
        ip::Output to_output(const ip::Data &data);

        std::string address_to_str(const ip::Address&);
    };
}


