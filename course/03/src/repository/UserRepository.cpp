#include "UserRepository.h"

cld::UserRepository::UserRepository(std::unique_ptr<soci::session> &c_session) : store(c_session) {}

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

bool cld::UserRepository::save(cld::User &user) {
    *store << "INSERT INTO users (id, email, password) VALUES (:id, :email, :password)", soci::use(user);
    return true;
}

cld::User cld::UserRepository::findById(long id) {
    return cld::User();
}

cld::User cld::UserRepository::findByEmail(std::string email) {
    return cld::User();
}
