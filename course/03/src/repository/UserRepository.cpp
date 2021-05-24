#include "UserRepository.h"

bool cld::UserRepository::save(cld::User &user) {
    auto session = SessionFactory::globalSession();
//    *session << "INSERT INTO users (id, email, password) VALUES (:id, :email, :password)", soci::use(user);
    return true;
}

cld::User cld::UserRepository::findById(long id) {
    return cld::User();
}

cld::User cld::UserRepository::findByEmail(std::string email) {
    return cld::User();
}
