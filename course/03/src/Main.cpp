#include <iostream>
#include <UserRepository.h>

#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include <soci/soci.h>
#include <postgresql/soci-postgresql.h>
#include "User1.h"

using namespace std;
using namespace soci;

namespace soci {
    template<>
    struct type_conversion<notSTD::User1> {
        typedef values base_type;

        static void from_base(const values &v, indicator, notSTD::User1 &user) {
            user.setId(v.get<long>("id"));
            user.setEmail(v.get<std::string>("email"));
            user.setPassword(v.get<std::string>("password"));
        }

        static void to_base(const notSTD::User1 &user, values &v, indicator &ind) {
            v.set("id", user.getId());
            v.set("email", user.getEmail());
            v.set("password", user.getPassword());
            ind = i_ok;
        }
    };
}

class Static {
public:

    unique_ptr<session> getSession() {
        if (store_m == nullptr)
            store_m = std::make_unique<soci::session>(soci::postgresql,
                                                      "host=postgres user=postgres password=password");
        return std::move(store_m);
    }

private:
    std::unique_ptr<soci::session> store_m{};

};

void save(std::unique_ptr<soci::session> session, notSTD::User1 &usr) {
    *session << "INSERT INTO users (id, email, password) VALUES (:id, :email, :password)", soci::use(usr);
}

int main() {
    auto user = notSTD::User1{};
    user.setId(10);
    user.setEmail("em");
    user.setPassword("pass");

    notSTD::User1 &usr = {user};

    auto st = Static{};
    save(st.getSession(), user);

//    auto ur = cld::UserRepository();
//    auto s = cld::User();
//    s.setId(1);
//    s.setEmail("email");
//    s.setPassword("pass");
//    ur.save(s);
    std::cout << "DONE " << __cplusplus;
}
