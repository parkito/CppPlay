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

void soci::type_conversion<cld::User>::from_base(const values &v, indicator, cld::User &user) {
    user.setId(v.get<long>("id"));
    user.setEmail(v.get<std::string>("email"));
    user.setPassword(v.get<std::string>("password"));
}

void soci::type_conversion<cld::User>::to_base(const cld::User &user, values &v, indicator &ind) {
    v.set("id", user.getId());
    v.set("email", user.getEmail());
    v.set("password", user.getPassword());
    ind = i_ok;
}