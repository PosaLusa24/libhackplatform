add_library(ram ram.cpp)
target_include_directories(ram PUBLIC ../include)
add_library(HackPlatform::Ram ALIAS ram)

add_library(rom rom.cpp)
target_include_directories(rom PUBLIC ../include)
add_library(HackPlatform::Rom ALIAS rom)

add_library(cpu cpu.cpp)
target_include_directories(cpu PUBLIC ../include)
add_library(HackPlatform::Cpu ALIAS cpu)

add_library(computer computer.cpp)
target_include_directories(computer PUBLIC ../include)
target_link_libraries(computer PRIVATE cpu ram rom)
add_library(HackPlatform::Computer ALIAS computer)

add_library(cpuemulator cpuemulator.cpp)
target_include_directories(cpuemulator PUBLIC ../include)
target_link_libraries(cpuemulator PRIVATE cpu)
add_library(HackPlatform::cpuemulator ALIAS cpuemulator)
