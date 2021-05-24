#include "UserRepository.h"

cld::UserRepository::UserRepository(soci::session &c_session) : store(c_session) {}

void cld::UserRepository::isave(soci::session &store, cld::User &usr) {
//    store << "INSERT INTO users (id, email, password) VALUES (:id, :email, :password)", soci::use(usr);
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

bool cld::UserRepository::save(cld::User &user) {
    isave(store, user);
    return true;
}

cld::User cld::UserRepository::findById(long id) {
    return cld::User();
}

cld::User cld::UserRepository::findByEmail(std::string email) {
    return cld::User();
}
