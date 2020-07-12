#ifndef HACKPLATFORM_CPU_HPP 
#define HACKPLATFORM_CPU_HPP 

#include <cstdint>
#include <string>

namespace HackPlatform {
    class Cpu {
        int16_t m_reg_ram;
        int16_t m_reg_a = 0;
        int16_t m_reg_d = 0;
        int16_t m_pc = 0;
        int16_t eval_expr(const std::string &expr);
        std::string extract_dest(const std::string &instruction);
        std::string extract_comp(const std::string &instruction);
        std::string extract_jump(const std::string &instruction);
    public:
        void process(const std::string &instruction, int16_t &reg_ram);
        void reset();
        int16_t get_reg_a();
        int16_t get_reg_d();
        int16_t get_pc();
    };
}

#endif
