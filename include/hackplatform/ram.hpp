#ifndef HACKPLATFORM_RAM_HPP
#define HACKPLATFORM_RAM_HPP

#include <cstdint>
#include <vector>

namespace HackPlatform {
    /**
     * A collection of 24,577 randomly accessible 16-bit registers.
     */
    class Ram {
        // Vector index corresponds to register address.
        std::vector<int16_t> m_memory;

    public:
        // Initialize all 24,577 registers to zero.
        Ram();

        // Set all registers to zero.
        void reset();

        // Return reference to register at `address`.
        int16_t& operator[](size_t address);
    };
}

#endif

