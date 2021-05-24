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

