#ifndef HACKPLATFORM_CPU_HPP 
#define HACKPLATFORM_CPU_HPP 

#include <cstdint>
#include <string>

namespace HackPlatform {
    /**
     * Executes non-symbolic Hack assembly instructions.
     *
     * This cpu differs from the conceptual Hack CPU in that
     * it directly executes non-symbolic assembly instructions,
     * as opposed to machine instructions.
     */
    class Cpu {
        // Currently selected ram register 'M'.
        int16_t m_reg_ram;

        // Address register 'A'.
        int16_t m_reg_a = 0;

        // Data register 'D'.
        int16_t m_reg_d = 0;

        // Program counter register.
        int16_t m_pc = 0;

        // Recursively evaluate 'comp' expression `expr` and return the result.
        int16_t eval_expr(const std::string& expr);

        // Extract 'dest' part from a C-instruction.
        std::string extract_dest(const std::string& instruction);

        // Extract 'comp' part from a C-instruction.
        std::string extract_comp(const std::string& instruction);

        // Extract 'jump' part from a C-instruction.
        std::string extract_jump(const std::string& instruction);

    public:
        /**
         * Parses and executes a single instruction.
         *
         * @param instruction A or C-instruction.
         * @param reg_ram Reference to an external ram register.
         */
        void execute(const std::string& instruction, int16_t& reg_ram);

        // Set internal registers to zero.
        void reset();

        // Return address register.
        int16_t get_reg_a();

        // Return data register.
        int16_t get_reg_d();

        // Return program counter.
        int16_t get_pc();
    };
}

#endif
