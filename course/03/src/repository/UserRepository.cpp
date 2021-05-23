#include "UserRepository.h"

bool cld::UserRepository::save(cld::User &user) {
    return false;
}

cld::User cld::UserRepository::findById(long id) {
    return cld::User();
}

cld::User cld::UserRepository::findByEmail(std::string email) {
    return cld::User();
}
