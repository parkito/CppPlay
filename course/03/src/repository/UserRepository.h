#pragma once

#include "User.h"
#include "SessionFactory.h"

namespace cld {
    class UserRepository {
    public:

        bool save(User &user);

        User findById(long id);

        User findByEmail(std::string email);

    };
}
