cmake_minimum_required(VERSION 3.15)

# set the project name
project(Tutorial)

set(CMAKE_CXX_STANDARD 20)

# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
if (UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif (WIN32)
    message("This is a Windows System")
endif ()# or use MATCHES to see if actual system name

# or use MATCHES to see if actual system name
# Darwin is Apple's system name
if (${CMAKE_SYSTEM_NAME} MATCHES Linux)
    add_definitions(-DCMAKEMACROSAMPLE="Linux")
elseif (${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DCMAKEMACROSAMPLE="Windows PC")
endif ()

#Static library
#set(SOURCES main.cpp
#        math/operations.cpp
#        math/operations.h)
#
#add_executable(main ${SOURCES})

#Shared/shared library
#add_library(math SHARED math/operations.cpp)
add_library(math STATIC math/operations.cpp)

add_executable(main main.cpp math)
target_link_libraries(main math)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost 1.74.0)# Check for libray, if found print message, include dirs and link libraries.
if (Boost_FOUND)
    message("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(main ${Boost_LIBRARIES})
elseif (NOT Boost_FOUND)
    message("Boost Not Found")
endif ()

#cmake -H. -Bcmake-build-debug && cd cmake-build-debug && make all && cd ..