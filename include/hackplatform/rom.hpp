#ifndef HACKPLATFORM_ROM_HPP
#define HACKPLATFORM_ROM_HPP

#include <string>
#include <vector>

namespace HackPlatform {
    class Rom {
        std::vector<std::string> m_memory;
    public:
        Rom(const std::string &program);
        size_t size();
        const std::string& operator[](size_t address);
    };
}

#endif

