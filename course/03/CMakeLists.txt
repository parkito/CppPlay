cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_COMPILER "gcc-11")

project("db-rest-prj")

find_package(SOCI REQUIRED)

message("Compiler ${CMAKE_CXX_COMPILER} version ${CMAKE_CXX_COMPILER_VERSION}")

add_library(
        db-rest
        src/entity/User.cpp
        src/repository/UserRepository.cpp
)

#set(CXXFLAGS ${CXXFLAGS} -std=c++2a)
add_compile_options(-std=c++2a)

add_executable(main src/Main.cpp)

target_include_directories(
        db-rest
        PUBLIC
        src/entity
        src/repository
)

target_link_libraries(
        main
        db-rest
        SOCI::soci_core
        SOCI::soci_postgresql
)