#include <iostream>
#include <catch2/catch.hpp>
using namespace std;

TEST_CASE("misc", "[misc]") {
    char c; cin >> c;
    REQUIRE(c == '3');
}
