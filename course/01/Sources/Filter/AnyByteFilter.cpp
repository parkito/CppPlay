#include <IpCommon.h>
#include "AnyByteFilter.h"

ip::Output ip::AnyByteFilter::filter(const ip::Data &data) {
    ip::Output output = ip::Output();

    for (auto &address:data) {
        for (auto &comp:address) {
            if (comp == 46) {
                output.push_back(address_to_str(address));
            }
        }
    }
    return output;
}

