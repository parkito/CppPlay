# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/allocator_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/allocator_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/allocator_test.dir/flags.make

CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.o: CMakeFiles/allocator_test.dir/flags.make
CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.o: ../Tests/allocator_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.o -c /tmp/02/Tests/allocator_test.cpp

CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/02/Tests/allocator_test.cpp > CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.i

CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/02/Tests/allocator_test.cpp -o CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.s

# Object files for target allocator_test
allocator_test_OBJECTS = \
"CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.o"

# External object files for target allocator_test
allocator_test_EXTERNAL_OBJECTS =

allocator_test: CMakeFiles/allocator_test.dir/Tests/allocator_test.cpp.o
allocator_test: CMakeFiles/allocator_test.dir/build.make
allocator_test: liballocator_lib.so
allocator_test: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so.1.71.0
allocator_test: CMakeFiles/allocator_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable allocator_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allocator_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/allocator_test.dir/build: allocator_test

.PHONY : CMakeFiles/allocator_test.dir/build

CMakeFiles/allocator_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/allocator_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/allocator_test.dir/clean

CMakeFiles/allocator_test.dir/depend:
	cd /tmp/02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/02 /tmp/02 /tmp/02/cmake-build-debug /tmp/02/cmake-build-debug /tmp/02/cmake-build-debug/CMakeFiles/allocator_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/allocator_test.dir/depend

