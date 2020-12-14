#pragma once

#include "../Common/IpCommon.h"
#include "../Validator/Validator.h"

namespace ip {
    class Reader {
    public:
        explicit Reader(const ip::Validator &valid);

        ip::Input read_input();

    private:
        ip::Validator validator;
    };
}
