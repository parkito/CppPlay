#include "UserRepository.h"

cld::UserRepository::UserRepository(std::unique_ptr<soci::session> &c_session) : store(c_session) {}


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
