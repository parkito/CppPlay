cmake_minimum_required(VERSION 3.15)

project(allocator VERSION 0.0.1)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_library(
        allocator_lib
        SHARED
        Sources/Calculator.cpp
)

target_include_directories(
        allocator_lib
        PUBLIC
        Sources
)

add_executable(allocator Sources/Main.cpp)
add_executable(allocator_test Tests/allocator_test.cpp)

set_target_properties(
        allocator
        allocator_lib
        allocator_test
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(
        allocator_test
        PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
        allocator
        PRIVATE
        allocator_lib
        Threads::Threads
)

target_link_libraries(
        allocator_test
        PRIVATE
        allocator_lib
        ${Boost_LIBRARIES}
)

install(TARGETS allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT artyom-karnov@yandex.ru)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(allocator_test allocator_test)

#cmake -H. -Bcmake-build-debug && cd cmake-build-debug && make all && make package
