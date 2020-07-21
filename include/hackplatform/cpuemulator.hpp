#ifndef HACKPLATFORM_CPUEMULATOR_HPP
#define HACKPLATFORM_CPUEMULATOR_HPP

#include <string>
#include <vector>
#include <hackplatform/cpu.hpp>
#include <hackplatform/rom2.hpp>

namespace HackPlatform {
    class CPUEmulator {
        std::vector<int16_t> m_ram;
        HackPlatform::Cpu m_cpu;
        HackPlatform::Rom2 m_rom;
    public:
        CPUEmulator();
        void load_asm(const std::string& program);
        void run_step(int steps = 1);
        void reset_ram();
        void restart();
        void set_ram(int16_t address, int16_t value);
        int16_t get_ram(int16_t address);
    };
}

#endif
