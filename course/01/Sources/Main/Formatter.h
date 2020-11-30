#pragma once

#include "IpCommon.h"

namespace ip {
    class Formatter {
    public:
        ip::Data format_input(ip::Input &data);

    private:
        std::string format_line(std::string &str);
    };
}

