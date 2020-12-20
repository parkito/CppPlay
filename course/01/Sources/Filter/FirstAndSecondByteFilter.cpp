#include <IpCommon.h>
#include "FirstAndSecondByteFilter.h"

ip::Output ip::FirstAndSecondByteFilter::filter(const ip::Data &data) {
    ip::Output output = ip::Output();

    for (auto &address:data) {
        if (address[0] == 46 && address[1] == 70) {
            output.push_back(address_to_str(address));
        }
    }

    return output;
}

