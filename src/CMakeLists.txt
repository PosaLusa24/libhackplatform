add_library(ram ram.cpp)
target_include_directories(ram PUBLIC ../include)

add_library(rom rom.cpp)
target_include_directories(rom PUBLIC ../include)

add_library(cpu cpu.cpp)
target_include_directories(cpu PUBLIC ../include)
