#include <iostream>
#include <UserRepository.h>

#include <iostream>
#include <string>
#include <exception>
#include <soci/soci.h>
#include <postgresql/soci-postgresql.h>

using namespace std;
using namespace soci;

struct Person {
    int id;
    string firstname;
    string lastname;
    int dob;
    string email;
};

namespace soci {
    template<>
    struct type_conversion<Person> {
        typedef values base_type;

        static void from_base(const values &v, indicator, Person &p) {
            p.id = v.get<int>("id");
            p.firstname = v.get<string>("firstname");
            p.lastname = v.get<string>("lastname");
            p.dob = v.get<int>("dob");
            p.email = v.get<string>("email");
        }

        static void to_base(const Person &p, values &v, indicator &ind) {
            v.set("id", p.id);
            v.set("firstname", p.firstname);
            v.set("lastname", p.lastname);
            v.set("dob", p.dob);
            v.set("email", p.email);
            ind = i_ok;
        }
    };
}

int main() {
    try {
        session sql(postgresql, "host=postgres user=postgres password=password");

//        sql << "CREATE DATABASE blog";
//        sql << "USE user";
        sql << "CREATE TABLE people (id INT, firstname TEXT, lastname TEXT, dob INT, email TEXT)";

        Person him{1, "Martin", "Vorbrodt", 19800830, "martin@vorbrodt.blog"};
        Person her{2, "Dorota", "Vorbrodt", 19800127, "dorota@vorbrodt.blog"};
        sql
                << "INSERT INTO people (id, firstname, lastname, dob, email) VALUES (:id, :firstname, :lastname, :dob, :email)", use(
                him);
        sql
                << "INSERT INTO people (id, firstname, lastname, dob, EMail) VALUES (:id, :firstname, :lastname, :dob, :email)", use(
                her);

        int count{};
        sql << "SELECT COUNT(*) FROM people", into(count);
        cout << "Table 'people' has " << count << " row(s)" << endl;

        Person pOut{};
        sql << "SELECT * FROM people WHERE id = 1", into(pOut);
        cout << pOut.firstname << ", " << pOut.lastname << ", " << pOut.dob << ", " << pOut.email << endl;

//        sql << "DROP TABLE people";
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }
}

//int main() {
//    auto ur = cld::UserRepository();
//    auto s = cld::User();
//    s.setId(1);
//    s.setEmail("email");
//    s.setPassword("pass");
//    ur.save(s);
//    std::cout << "DONE " << __cplusplus;
//}
