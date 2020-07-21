#include <fstream>
#include <iostream>
#include <catch2/catch.hpp>

#include <hackplatform/cpuemulator.hpp>

using namespace std;

TEST_CASE("misc", "[misc]") {
    ofstream file("lol.asm", ios::out);
    file << R"(
    // Nice file
    M=M+1//Nicecomment
    (LABEL)// sdf   
    @DFSD
)";
    file.close();
    HackPlatform::CPUEmulator ce;
    ce.load_asm("lol.asm");
    REQUIRE(1);
}
