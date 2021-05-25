#include "PropertyHolder.h"

cld::PropertyHolder::PropertyHolder() = default;

std::unique_ptr<cld::Property> cld::PropertyHolder::property{nullptr};

std::unique_ptr<cld::Property> cld::PropertyHolder::getProperty() {
    if (property == nullptr) {
        property = ConfigReader().readProperty();
    }
    return std::move(property);
}

void cld::PropertyHolder::renew() {
    property = nullptr;
}

