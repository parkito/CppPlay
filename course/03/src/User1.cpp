#include "User1.h"

long notSTD::User1::getId() const {
    return id;
}

std::string notSTD::User1::getEmail() const {
    return email;
}

std::string notSTD::User1::getPassword() const {
    return password;
}

void notSTD::User1::setId(const long s_id) {
    this->id = s_id;
}

void notSTD::User1::setEmail(const std::string &s_email) {
    this->email = s_email;
}

void notSTD::User1::setPassword(const std::string &s_password) {
    this->password = s_password;
}
