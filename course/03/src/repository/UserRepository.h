#pragma once

#include "User.h"
#include <soci/soci.h>
#include "SessionFactory.h"

namespace cld {
    class UserRepository {
    public:
        explicit UserRepository(std::unique_ptr<soci::session> &);

        bool save(cld::User &user);

        User findById(long id);

        User findByEmail(std::string email);

    private:
        std::unique_ptr<soci::session> &store;
    };
}