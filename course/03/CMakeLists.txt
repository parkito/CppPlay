cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project("db-rest-prj")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
        db-rest
        src/entity/User.cpp
        src/repository/UserRepository.cpp
)

#set(CXXFLAGS ${CXXFLAGS} -std=c++2a)
add_compile_options(-std=c++2a)
message("Version ${CMAKE_CXX_COMPILER_VERSION}")

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
)