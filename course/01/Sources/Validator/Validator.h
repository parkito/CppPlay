#pragma once

#include "../Common/IpCommon.h"

namespace ip {
    class Validator {
    public:
        void validate_line(const std::string &line);
    };
}