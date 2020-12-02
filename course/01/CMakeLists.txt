cmake_minimum_required(VERSION 3.15)

project(ip_filter VERSION 0.0.1)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter Sources/Main.cpp)

add_library(ip_filter_lib
        Sources/Main/Reader.cpp
        Sources/Main/Formatter.cpp
        Sources/Main/Filter/Filter.cpp
        Sources/Main/Runner.cpp
        Sources/Main/Validator.cpp
        Sources/Main/Filter/SortedFilter.cpp
        Sources/Main/Filter/FirstByteFilter.cpp
        Sources/Main/Filter/FirstAndSecondByteFilter.cpp
        Sources/Main/Filter/AnyFilter.cpp)

add_executable(test_version Tests/test_version.cpp)

set_target_properties(ip_filter ip_filter_lib test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(
        ip_filter
        ip_filter_lib
        Threads::Threads
)

target_link_libraries(test_version
        ${Boost_LIBRARIES}
        ip_filter_lib
        )

install(TARGETS ip_filter RUNTIME DESTINATION bin)

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
