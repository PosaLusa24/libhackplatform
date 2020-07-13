#ifndef HACKPLATFORM_ROM_HPP
#define HACKPLATFORM_ROM_HPP

#include <string>
#include <vector>

namespace HackPlatform {
    /**
     * Stores a sequence of non-symbolic assembly instructions.
     *
     * This rom differs from the conceptual Hack ROM in that
     * it converts symbolic assembly instructions and stores
     * them as non-symbolic ones, as opposed to directly storing
     * machine instructions.
     */
    class Rom {
        // Vector index corresponds to instruction address.
        std::vector<std::string> m_memory;
    public:
        // Constructs empty rom.
        Rom();

        /**
         * Constructs rom from a symbolic .asm program.
         *
         * Conversion involves the resolution of label and variable symbols.
         */
        Rom(const std::string& program);

        // Returns the number of instructions.
        size_t size() const;

        // Copy contents of one rom to another.
        Rom& operator=(const Rom& rom);

        // Move contents of one rom to another.
        Rom& operator=(Rom&& rom);

        // Return instruction at `address`.
        const std::string& operator[](size_t address) const;
    };
}

#endif

