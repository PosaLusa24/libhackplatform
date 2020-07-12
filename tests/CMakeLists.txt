add_executable(cputest cpu.test.cpp)
target_link_libraries(cputest PRIVATE cpu libcatch2)

catch_discover_tests(cputest)
