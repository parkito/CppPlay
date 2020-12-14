#include "IReader.h"

namespace ip {
    class StdReader : public IReader {
    public:
        explicit StdReader(std::unique_ptr<ip::Validator> valid) : IReader(std::move(valid)) {}

        Input read_input(std::optional<std::string>) override;
    };
}