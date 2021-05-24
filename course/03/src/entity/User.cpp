#include "User.h"

long cld::User::getId() const {
    return id;
}

std::string cld::User::getEmail() const {
    return email;
}

std::string cld::User::getPassword() const {
    return password;
}

void cld::User::setId(const long s_id) {
    this->id = s_id;
}

void cld::User::setEmail(const std::string &s_email) {
    this->email = s_email;
}

void cld::User::setPassword(const std::string &s_password) {
    this->password = s_password;
}

