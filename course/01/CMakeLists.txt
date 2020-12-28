cmake_minimum_required(VERSION 3.15)

project(ip_filter VERSION 0.0.1)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_library(
        ip_filter_lib
        Sources/Filter/Filter.cpp
        Sources/Filter/FirstAndSecondByteFilter.cpp
        Sources/Filter/FirstByteFilter.cpp
        Sources/Filter/AnyByteFilter.cpp
        Sources/Comparator/LexicographicComparator.cpp
        Sources/Filter/SortedFilter.cpp
        Sources/Formatter/Formatter.cpp
        Sources/Reader/FileReader.cpp
        Sources/Reader/StdReader.cpp
        Sources/Runner/Runner.cpp
        Sources/Validator/Validator.cpp
)

target_include_directories(
        ip_filter_lib
        PUBLIC
        Sources/Common
        Sources/Comparator
        Sources/Filter
        Sources/Formatter
        Sources/Reader
        Sources/Runner
        Sources/Validator
)

add_executable(ip_filter Sources/Main.cpp)
add_executable(ip_filter_test Tests/ip_filter_test.cpp)

set_target_properties(
        ip_filter
        ip_filter_lib
        ip_filter_test
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(
        ip_filter_test
        PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
        ip_filter
        PRIVATE
        ip_filter_lib
        Threads::Threads
)

target_link_libraries(
        ip_filter_test
        PRIVATE
        ip_filter_lib
        ${Boost_LIBRARIES}
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

add_test(filter_test ip_filter_test)

#cmake -H. -Bcmake-build-debug && cd cmake-build-debug && make all && make package
