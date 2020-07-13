#include <string>
#include <hackplatform/computer.hpp>
#include <hackplatform/rom.hpp>
#include "../extern/catch2/catch.hpp"

namespace Hack = HackPlatform;

Hack::Computer c;
std::string program = R"(
@69
D=A
@2
M=D+1
)";
std::string program2 = R"(
@68
D=A
@2
M=D-A
)";

TEST_CASE("test", "[1]") {
    c.load_rom(Hack::Rom(program2));
    c.run(5);
    REQUIRE(c.ram(2) == 66);
}
