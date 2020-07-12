#ifndef HACKPLATFORM_RAM_HPP
#define HACKPLATFORM_RAM_HPP

#include <cstdint>
#include <vector>

namespace HackPlatform {
    class Ram {
        std::vector<int16_t> m_memory;
    public:
        Ram();
        void reset();
        int16_t& operator[](size_t address);
    };
}

#endif

