#pragma once

#include <string>
#include <values.h>

namespace cld {
    class User {

    public:
        [[nodiscard]] long getId() const;

        [[nodiscard]] std::string getEmail() const;

        [[nodiscard]] std::string getPassword() const;

        void setId(long s_id);

        void setEmail(const std::string &s_email);

        void setPassword(const std::string &s_password);

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

        static void from_base(const values &v, indicator, cld::User &user);

        static void to_base(const cld::User &user, values &v, indicator &ind);
    };
}