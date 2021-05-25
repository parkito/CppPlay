#pragma once

#include <memory>
#include "Property.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;

namespace cld {
    class ConfigReader {
    public:
        std::unique_ptr<cld::Property> readProperty();

    };
}

