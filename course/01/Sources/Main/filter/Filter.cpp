#include "Filter.h"

ip::Output ip::Filter::to_output(const ip::Data &data) {
    ip::Output output;

    for (auto &line:data) {
        std::string res;
        for (size_t i = 0; i < line.size(); ++i) {
            if (i != 3) {
                res += (std::to_string(line[i]) + ".");
            } else {
                res += (std::to_string(line[i]));
            }
        }
        output.push_back(res);
    }

    return output;
}
