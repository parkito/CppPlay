cmake_minimum_required(VERSION 3.16)

project(cli VERSION 0.0.1)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(spdlog REQUIRED)

configure_file(Ops/version.h.in ${PROJECT_SOURCE_DIR}/Sources/Main/Version.h)

add_executable(cli Sources/Main/Main.cpp)

add_library(cli_lib Sources/Main/Lib.cpp)

add_executable(test_version Tests/test_version.cpp)

include_directories(include)

set_target_properties(cli cli_lib test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(cli
        spdlog::spdlog
        cli_lib
        Threads::Threads
        )

target_link_libraries(test_version
        spdlog::spdlog
        ${Boost_LIBRARIES}
        cli_lib
        )

install(TARGETS cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT artyom-karnov@yandex.ru)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(cli_lib_tests test_version)

#cmake -H. -Bcmake-build-debug && cd cmake-build-debug && make all && make package
