#ifndef HACKPLATFORM_COMPUTER_HPP 
#define HACKPLATFORM_COMPUTER_HPP 

#include <hackplatform/cpu.hpp>
#include <hackplatform/ram.hpp>
#include <hackplatform/rom.hpp>

namespace HackPlatform {
    class Computer {
        HackPlatform::Ram m_ram;
        HackPlatform::Rom m_rom;
        HackPlatform::Cpu m_cpu;
    public:
        void load_rom(const HackPlatform::Rom &rom);
        void run_for_cycles(int cycles = 1);
        HackPlatform::Ram dump_ram();
    };
}

#endif
