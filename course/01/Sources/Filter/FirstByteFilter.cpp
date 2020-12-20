#include <IpCommon.h>
#include "FirstByteFilter.h"

ip::Output ip::FirstByteFilter::filter(const ip::Data &data) {
    ip::Output result = ip::Output();
    for (auto &address:data) {
        if (address[0] == 1) {
            result.push_back(address_to_str(address));
        } else {
            break;
        }
    }
    return ip::Output();
}
