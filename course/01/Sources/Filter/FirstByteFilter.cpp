#include <IpCommon.h>
#include "FirstByteFilter.h"

ip::Output ip::FirstByteFilter::filter(const ip::Data &data) {
    ip::Output output = ip::Output();
    for (auto &address:data) {
        if (address[0] == 1) {
            output.push_back(address_to_str(address));
        }
    }
    return output;
}
