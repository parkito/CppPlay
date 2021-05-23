#include "User.h"

long cld::User::getId() const {
    return id;
}

const std::string &cld::User::getEmail() const {
    return email;
}

const std::string &cld::User::getPassword() const {
    return password;
}

void cld::User::setId(long id) {
    User::id = id;
}

void cld::User::setEmail(const std::string &email) {
    User::email = email;
}

void cld::User::setPassword(const std::string &password) {
    User::password = password;
}
