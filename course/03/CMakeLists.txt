cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project("db-rest-prj")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
        db-rest
        Source/User.cpp
)

#set(CXXFLAGS ${CXXFLAGS} -std=c++2a)
add_compile_options(-std=c++2a)
message("Version ${CMAKE_CXX_COMPILER_VERSION}")

add_executable(main Source/Main.cpp)

target_include_directories(
        db-rest
        PUBLIC
        Source
)

target_link_libraries(
        main
        db-rest
)