cmake_minimum_required(VERSION 3.15)
project(CppPlay)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/common)
include_directories(src/cloud)

add_executable(cloud src/cloud/main.cpp)

add_executable(main1 src/01_basics/01_hello.cpp)
add_executable(main2 src/01_basics/02_type.cpp)
add_executable(main3 src/01_basics/03_const.cpp)
add_executable(main4 src/01_basics/04_pointers.cpp)
add_executable(main5 src/01_basics/05_switch.cpp)
add_executable(main6 src/01_basics/06_struct.cpp)
add_executable(main7 src/01_basics/07_class.cpp)
add_executable(main8 src/01_basics/08_namespace.cpp)
add_executable(main9 src/01_basics/09_exceptions.cpp)
add_executable(main10 src/01_basics/10_asserts.cpp)