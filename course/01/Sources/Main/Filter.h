#pragma once

#include "IpCommon.h"

namespace ip {
    class Filter {
        virtual ip::Output filter(ip::Data &data);
    };
}


