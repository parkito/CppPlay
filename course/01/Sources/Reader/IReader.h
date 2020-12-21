#pragma once

#include <optional>
#include <memory>
#include "IpCommon.h"
#include "Validator.h"

namespace ip {
    class IReader {
    protected:
        const std::unique_ptr<ip::Validator> validator;

    public:
        explicit IReader(std::unique_ptr<ip::Validator> &valid) : validator(std::move(valid)) {};

        virtual ip::Input read_input(std::optional<std::string>) = 0;
    };
}
