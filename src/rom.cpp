#include <map>
#include <sstream>

#include <hackplatform/rom.hpp>

HackPlatform::Rom::Rom(const std::string &program) {

    // initialize symbol table
    std::map<std::string, int> syms {
        {"SP", 0},
        {"LCL", 1},
        {"ARG", 2},
        {"THIS", 3},
        {"THAT", 4},
        {"SCREEN", 16384},
        {"KBD", 24576}
    };
    for(int i = 0; i < 16; ++i)
        syms.insert(make_pair("R" + std::to_string(i), i));

    // build symbol table and partial rom
    std::string line;
    std::stringstream program_stream(program);
    while(getline(program_stream, line)) {
        std::string firstw;
        std::stringstream ss(line);
        ss >> firstw;
        if(firstw.empty() || firstw[0] == '/') continue;
        if(firstw[0] == '(') {
            syms.insert(make_pair(line.substr(1, line.size() - 2), m_memory.size()));
            continue;
        }
        m_memory.push_back(firstw);
    }

    // resolve symbols in rom
    int counter {16};
    for(auto &ins: m_memory) {
        if(ins[0] != '@') continue;
        std::string sym {ins.substr(1)};
        if(isdigit(sym[0])) continue;
        if(syms.find(sym) != syms.end()) {
            ins = "@" + std::to_string(syms[sym]);
        } else {
            syms.insert(make_pair(sym, counter));
            ins = "@" + std::to_string(counter++);
        }
    }
}

size_t HackPlatform::Rom::size() {
    return m_memory.size();
}

const std::string& HackPlatform::Rom::operator[](size_t address) {
    return m_memory[address];
}

