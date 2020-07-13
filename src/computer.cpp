#include <hackplatform/computer.hpp>

void HackPlatform::Computer::reset() {
    m_ram.reset();
    m_cpu.reset();
}

void HackPlatform::Computer::load_rom(const HackPlatform::Rom& rom) {
    this->reset();
    m_rom = rom;
}

void HackPlatform::Computer::load_rom(HackPlatform::Rom&& rom) {
    this->reset();
    m_rom = std::move(rom);
}

void HackPlatform::Computer::run(int cycles) {
    while(cycles--) {
        if(m_cpu.get_pc() >= m_rom.size()) return;
        m_cpu.execute(m_rom[m_cpu.get_pc()], m_ram[m_cpu.get_reg_a()]);
    }
}

int16_t& HackPlatform::Computer::ram(size_t address) {
    return m_ram[address];
}

