add_executable(cputest cpu.test.cpp)
target_link_libraries(cputest PRIVATE cpu libcatch2)

add_executable(computertest computer.test.cpp)
target_link_libraries(computertest PRIVATE computer cpu ram rom libcatch2)

catch_discover_tests(cputest)
catch_discover_tests(computertest)
