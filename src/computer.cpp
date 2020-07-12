#include <hackplatform/computer.hpp>

void HackPlatform::Computer::load_rom(const HackPlatform::Rom &rom) {
    m_cpu.reset();
    m_rom = rom;
}

void HackPlatform::Computer::run_for_cycles(int cycles) {
    while(cycles--) {
        if(m_cpu.get_pc() >= m_rom.size()) return;
        m_cpu.process(m_rom[m_cpu.get_pc()], m_ram[m_cpu.get_reg_a()]);
    }
}

HackPlatform::Ram HackPlatform::Computer::dump_ram() {
    return m_ram;
}

