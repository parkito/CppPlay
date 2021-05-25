#include <iostream>
#include <UserRepository.h>
#include "property/ConfigReader.h"

int main() {
//    auto user = cld::User{};
//    user.setId(12);
//    user.setEmail("em");
//    user.setPassword("pass");
//
//    cld::User &usr = {user};
//
//    auto st = SessionFactory{};
//    auto session = st.getSession();
//    auto repo = cld::UserRepository{session};
//
//    repo.save(usr);


    auto cr = cld::ConfigReader{};
    auto prop = cr.readProperty();
    std::cout << "DONE " << __cplusplus;
}
