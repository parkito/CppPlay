#include <IpCommon.h>
#include "FirstAndSecondByteFilter.h"

ip::Output ip::FirstAndSecondByteFilter::filter(const ip::Data &data) {
    ip::Output result = ip::Output();
    for (auto &address:data) {
        if (address[0] == 46 && address[1] == 70) {
            result.push_back(address_to_str(address));
        }
    }
    return ip::Output();
}

