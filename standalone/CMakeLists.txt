cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(GreeterStandalone LANGUAGES CXX)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(
  NAME cxxopts
  GITHUB_REPOSITORY jarro2783/cxxopts
  VERSION 2.2.0
  OPTIONS "CXXOPTS_BUILD_EXAMPLES Off" "CXXOPTS_BUILD_TESTS Off"
)

CPMAddPackage(NAME Greeter SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

set(CMAKE_CXX_STANDARD 17)

# ---- Create standalone executable ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(GreeterStandalone ${sources})

add_executable(main1 src/basics/01_hello.cpp)
add_executable(main2 src/basics/02_type.cpp)
add_executable(main3 src/basics/03_const.cpp)
add_executable(main4 src/basics/04_pointers.cpp)
add_executable(main5 src/basics/05_switch.cpp)
add_executable(main6 src/basics/06_struct.cpp)
add_executable(main7 src/basics/07_class.cpp)
add_executable(main8 src/basics/08_namespace.cpp)
add_executable(main9 src/basics/09_exceptions.cpp)
add_executable(main10 src/basics/10_asserts.cpp)
add_executable(main11 src/basics/11_returning.cpp)
add_executable(main12 src/basics/12_binding.cpp)
