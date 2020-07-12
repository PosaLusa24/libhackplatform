#include <hackplatform/cpu.hpp>

void HackPlatform::Cpu::process(const std::string &instruction, int16_t &reg_ram) {
    m_reg_ram = reg_ram;

    // a-instruction
    if(instruction[0] == '@') {
        m_reg_a = stoi(instruction.substr(1));
        ++m_pc;
        return;
    }

    // c-instruction
    std::string dest = extract_dest(instruction);
    std::string comp = extract_comp(instruction);
    std::string jump = extract_jump(instruction);

    // comp
    int16_t result = eval_expr(comp);

    // dest
    for(char c: dest) {
        if(c == 'A') m_reg_a = result;
        else if(c == 'D') m_reg_d = result;
        else reg_ram = result;
    }

    // jump
    if(jump == "JMP" ||
            jump == "JGT" && result > 0 || 
            jump == "JEQ" && result == 0 || 
            jump == "JGE" && result >= 0 || 
            jump == "JLT" && result < 0 || 
            jump == "JNE" && result != 0 || 
            jump == "JLE" && result <= 0)
        m_pc = m_reg_a;
    else
        ++m_pc;
}

void HackPlatform::Cpu::reset() {
    m_reg_a = 0;
    m_reg_d = 0;
    m_pc = 0;
}

int16_t HackPlatform::Cpu::get_reg_a() {
    return m_reg_a;
}

int16_t HackPlatform::Cpu::get_reg_d() {
    return m_reg_d;
}

int16_t HackPlatform::Cpu::get_pc() {
    return m_pc;
}

int16_t HackPlatform::Cpu::eval_expr(const std::string &expr) {
    if(expr.size() == 1) {
        if(expr[0] == 'A') return m_reg_a;
        if(expr[0] == 'D') return m_reg_d;
        if(expr[0] == 'M') return m_reg_ram;
        if(expr[0] == '1') return 1;
        if(expr[0] == '0') return 0;
    }
    if(expr.size() == 2) {
        if(expr[0] == '-')
            return -eval_expr(std::string(1, expr[1]));
        if(expr[0] == '!')
            return !eval_expr(std::string(1, expr[1]));
    }
    if(expr.size() == 3) {
        if(expr[1] == '+')
            return eval_expr(std::string(1, expr[0]))
                + eval_expr(std::string(1, expr[2]));
        if(expr[1] == '-')
            return eval_expr(std::string(1, expr[0]))
                - eval_expr(std::string(1, expr[2]));
        if(expr[1] == '|')
            return eval_expr(std::string(1, expr[0]))
                | eval_expr(std::string(1, expr[2]));
        if(expr[1] == '&')
            return eval_expr(std::string(1, expr[0]))
                & eval_expr(std::string(1, expr[2]));
    }
    return 0;
}

std::string HackPlatform::Cpu::extract_dest(const std::string &ins) {
    std::string result {};
    for(char c: ins) {
        if(c == '=') return result;
        result += c;
    }
    return "";
}

std::string HackPlatform::Cpu::extract_comp(const std::string &ins) {
    std::string result {};
    for(char c: ins) {
        if(c == ';') break;
        result += c;
        if(c == '=') result = "";
    }
    return result;
}

std::string HackPlatform::Cpu::extract_jump(const std::string &ins) {
    std::string result {};
    bool found;
    for(char c: ins) {
        result += c;
        if(c == ';') {
            found = true;
            result = "";
        }
    }
    return found ? result : "";
}

