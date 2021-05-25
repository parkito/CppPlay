#pragma once

#include <memory>
#include "ConfigReader.h"

namespace cld {
    class PropertyHolder {
    public:
        static std::unique_ptr<cld::Property> getProperty();

        static void renew();

    private:
        PropertyHolder();

        static std::unique_ptr<cld::Property> property;
    };

}

