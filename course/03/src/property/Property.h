#pragma once

#include <string>

namespace cld {
    class Db;

    class Property {
    public:
        Property();

        [[nodiscard]] Db getDb() const;

        void setDb(std::unique_ptr<cld::Db> c_db);

    private:
        std::unique_ptr<cld::Db> db;
    };

    class Db {
    public:
        explicit Db(std::string host = "", unsigned int port = 0, std::string user = "", std::string password = "");

        [[nodiscard]] std::string getHost() const;

        [[nodiscard]] unsigned int getPort() const;

        [[nodiscard]] std::string getUser() const;

        [[nodiscard]] std::string getPassword() const;

    private:
        std::string host;
        unsigned int port;
        std::string user;
        std::string password;
    };
}
