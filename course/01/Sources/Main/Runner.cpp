#include "Runner.h"
#include "Formatter.h"
#include "Reader.h"

ip::Output &ip::Runner::run() {
    ip::Validator validator;
    ip::Reader reader{validator}; //use move semantic
    ip::Formatter formatter;

    auto input = reader.read_input();
    auto formattedInput = formatter.format_input(input);

    return ip::Output();
}

std::vector<ip::Filter> ip::Runner::to_filters(ip::Filter const &filters ...) {
    return {filters};
}
