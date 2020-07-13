#include <hackplatform/cpu.hpp>
#include "../extern/catch2/catch.hpp"

HackPlatform::Cpu cpu;
int16_t reg_ram;

TEST_CASE("Test A-instruction and pc", "[1]") {
    cpu.reset();
    cpu.execute("@69", reg_ram);
    REQUIRE(cpu.get_reg_a() == 69);
    REQUIRE(cpu.get_pc() == 1);
}

TEST_CASE("Test dest (AMD) and pc", "[2]") {
    cpu.reset();
    cpu.execute("@69", reg_ram);
    cpu.execute("AMD=A", reg_ram);
    REQUIRE(cpu.get_reg_a() == 69);
    REQUIRE(cpu.get_reg_d() == 69);
    REQUIRE(reg_ram == 69);
    REQUIRE(cpu.get_pc() == 2);
}

TEST_CASE("Test comp (A+M)", "[3]") {
    cpu.reset();
    cpu.execute("@60", reg_ram);
    cpu.execute("M=A", reg_ram);
    cpu.execute("D=A+M", reg_ram);
    REQUIRE(cpu.get_reg_a() == 60);
    REQUIRE(cpu.get_reg_d() == 120);
    REQUIRE(reg_ram == 60);
}

TEST_CASE("Test jump (JMP)", "[4]") {
    cpu.reset();
    cpu.execute("@60", reg_ram);
    cpu.execute("0;JMP", reg_ram);
    REQUIRE(cpu.get_pc() == 60);
}

TEST_CASE("Test jump (JGT)", "[5]") {
    cpu.reset();
    cpu.execute("@12", reg_ram);
    cpu.execute("D=A", reg_ram);
    cpu.execute("@60", reg_ram);
    cpu.execute("D;JGT", reg_ram);
    REQUIRE(cpu.get_pc() == 60);
}

TEST_CASE("Test multicommand", "[6]") {
    cpu.reset();
    cpu.execute("@0", reg_ram);
    cpu.execute("D=A", reg_ram);
    cpu.execute("@60", reg_ram);
    cpu.execute("MD=D-1;JLT", reg_ram);
    REQUIRE(cpu.get_pc() == 60);
    REQUIRE(cpu.get_reg_d() == -1);
    REQUIRE(reg_ram == -1);
}

