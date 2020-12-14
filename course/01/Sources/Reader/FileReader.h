#pragma once

#include "IReader.h"

namespace ip {
    class FileReader : public IReader {
    public:
        explicit FileReader(std::unique_ptr<ip::Validator> &valid);

        Input read_input(std::optional<std::string>) override;
    };
}
