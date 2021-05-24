#include <iostream>
#include <UserRepository.h>

int main() {
    auto user = cld::User{};
    user.setId(11);
    user.setEmail("em");
    user.setPassword("pass");

    cld::User &usr = {user};

    auto st = SessionFactory{};
    auto session = st.getSession();
    auto repo = cld::UserRepository{session};

    repo.save(usr);
    std::cout << "DONE " << __cplusplus;
}
