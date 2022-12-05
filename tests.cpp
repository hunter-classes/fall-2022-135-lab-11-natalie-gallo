#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

//add tests here...
TEST_CASE("Task A"){
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

    Profile p2("tarma1", "Tarma Roving");
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("Task B"){
    Network tester;
    CHECK(tester.addUser("nat", "Natalie") == true);
    CHECK(tester.addUser("sam", "Sammy") == true);
    CHECK(tester.addUser("lilly", "Lilly") == true);
    CHECK(tester.addUser("lilly", "Lilly") == false);
}

TEST_CASE("Task C"){
    Network tester2;
    CHECK(tester2.addUser("nat", "Natalie") == true);
    CHECK(tester2.addUser("sam", "Sammy") == true);
    CHECK(tester2.addUser("lilly", "Lilly") == true);

    CHECK(tester2.follow("nat", "sam") == true);
    CHECK(tester2.follow("sam", "nat") == true);
    CHECK(tester2.follow("lilly", "nat") == true);
}