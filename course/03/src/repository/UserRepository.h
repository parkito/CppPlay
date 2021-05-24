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

namespace soci {
    template<>
    struct type_conversion<cld::User> {
        typedef values base_type;

        static void from_base(const values &v, indicator, cld::User &user);

        static void to_base(const cld::User &user, values &v, indicator &ind);
    };
}