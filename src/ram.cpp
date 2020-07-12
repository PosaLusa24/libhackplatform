#include <hackplatform/ram.hpp>

HackPlatform::Ram::Ram(): m_memory(24577) {}

void HackPlatform::Ram::reset() {
    m_memory.assign(24577, 0);
}

int16_t& HackPlatform::Ram::operator[](size_t address) {
    return m_memory[address];
}

