#pragma once

#include <glob.h>
#include <string>

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

