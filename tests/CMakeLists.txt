FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.0
)
FetchContent_MakeAvailable(catch2)

add_library(testlib test.cpp)
target_link_libraries(testlib PUBLIC Catch2::Catch2)

add_executable(misc misc.cpp)
target_link_libraries(misc PUBLIC testlib)
catch_discover_tests(misc)

add_executable(cpu_test cpu.test.cpp)
target_link_libraries(cpu_test PRIVATE testlib HackPlatform::Cpu)
catch_discover_tests(cpu_test)

add_executable(computer_test computer.test.cpp)
target_link_libraries(computer_test PRIVATE testlib HackPlatform::Computer)
catch_discover_tests(computer_test)
