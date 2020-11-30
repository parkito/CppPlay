#pragma once

#include "IpCommon.h"
#include "Validator.h"

namespace ip {
    class Reader {
    public:
        explicit Reader(const ip::Validator &val);

        ip::Input read_input();

    private:
        ip::Validator &validator;
    };
}
