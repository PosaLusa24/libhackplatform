#include <fstream>
#include <sstream>
#include <iostream>
#include <hackplatform/cpuemulator.hpp>

HackPlatform::CPUEmulator::CPUEmulator(): m_ram(24577) {}

void HackPlatform::CPUEmulator::load_asm(const std::string& program) {
    std::stringstream ss;

    std::ifstream file(program, std::ios::in);
    if(file) ss << file.rdbuf();
    else ss << program;

    m_rom.reset();
    m_cpu.reset();
    char ch = ss.get();
    while(ch != EOF) {
        if(ch == '/' and ss.peek() == '/') {
            while(ch != '\n' and ch != EOF)
                ch = ss.get();
            continue;
        } else if(ch == ' ' or ch == '\n') {
            ch = ss.get();
            continue;
        } else {
            std::string instruction;
            while(ch != ' ' and ch != '\n' and ch != '/' and ch != EOF) {
                instruction += ch;
                ch = ss.get();
            }
            m_rom.add_instruction(instruction);
        }
    }
}

void HackPlatform::CPUEmulator::run_step(int steps) {
    while(steps--) {
        if(m_cpu.get_pc() >= m_rom.size()) return;
        m_cpu.execute(
            m_rom.get_instruction(m_cpu.get_pc()),
            m_ram[m_cpu.get_reg_a()]
        );
    }
}

void HackPlatform::CPUEmulator::reset_ram() {
    m_ram.assign(24577, 0);
}

void HackPlatform::CPUEmulator::restart() {
    m_cpu.reset();
}

void HackPlatform::CPUEmulator::set_ram(int16_t address, int16_t value) {
    m_ram[address] = value;
}

int16_t HackPlatform::CPUEmulator::get_ram(int16_t address) {
    return m_ram[address];
}
