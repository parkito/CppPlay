#pragma once

#include "User.h"

namespace cld {
    class UserRepository {
    public:

        bool save(User &user);

        User findById(long id);

        User findByEmail(std::string email);

    };
}
