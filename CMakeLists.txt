cmake_minimum_required(VERSION 3.15)
project(libhackplatform)

add_subdirectory(src)
add_subdirectory(extern/catch2)
include(CTest)
include(cmake/Catch.cmake)
add_subdirectory(tests)
