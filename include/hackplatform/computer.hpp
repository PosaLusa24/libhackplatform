#ifndef HACKPLATFORM_COMPUTER_HPP 
#define HACKPLATFORM_COMPUTER_HPP 

#include <hackplatform/cpu.hpp>
#include <hackplatform/ram.hpp>
#include <hackplatform/rom.hpp>

namespace HackPlatform {
    /**
     * Runs Hack assembly programs.
     * 
     * Program must be loaded as rom before running.
     * Running a program results in manipulation of internal ram,
     * whose contents can be analysed via `ram(address)`
     */
    class Computer {
        // Internal ram
        HackPlatform::Ram m_ram;

        // Internal rom
        HackPlatform::Rom m_rom;

        // Internal cpu
        HackPlatform::Cpu m_cpu;

    public:
        // Reset internal cpu's program counter and ram's contents.
        void reset();

        // Resets computer and copy `rom` into internal rom.
        void load_rom(const HackPlatform::Rom& rom);

        // Resets computer and move `rom` into internal rom.
        void load_rom(HackPlatform::Rom&& rom);

        // Process internal rom for `cycles` (1 cycle = 1 program counter incrementation)
        void run(int cycles = 1);

        // Return reference to `address` of internal ram
        int16_t& ram(size_t address);
    };
}

#endif
