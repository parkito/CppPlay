#pragma once

#include <string>
#include <values.h>

namespace cld {
    class User {

    public:
        long getId() const;

        const std::string &getEmail() const;

        const std::string &getPassword() const;

        void setId(long id);

        void setEmail(const std::string &email);

        void setPassword(const std::string &password);

    private:
        long id;
        std::string email;
        std::string password;
    };
}

namespace soci {
    template<>
    struct type_conversion<cld::User> {
        typedef values base_type;

        static void from_base(const values &v, indicator, cld::User &user) {
            user.setId(v.get<long>("id"));
            user.setEmail(v.get<std::string>("email"));
            user.setPassword(v.get<std::string>("password"));
        }

        static void to_base(const cld::User &user, values &v, indicator &ind) {
            v.set("id", user.getId());
            v.set("email", user.getEmail());
            v.set("password", user.getPassword());
            ind = i_ok;
        }
    };
}