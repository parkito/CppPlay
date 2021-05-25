#include <memory>
#include "Property.h"

std::string cld::Db::getHost() const {
    return host;
}

unsigned int cld::Db::getPort() const {
    return port;
}

std::string cld::Db::getUser() const {
    return user;
}

std::string cld::Db::getPassword() const {
    return password;
}

cld::Db::Db(std::string host, unsigned int port, std::string user, std::string password) :
        host(std::move(host)),
        port(port),
        user(std::move(user)),
        password(std::move(password)) {}

cld::Db cld::Property::getDb() const {
    return *db;
}

void cld::Property::setDb(std::unique_ptr<cld::Db> c_db) {
    db = std::move(c_db);
}

cld::Property::Property() : db(nullptr) {}
