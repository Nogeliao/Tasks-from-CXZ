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
CMAKE_SOURCE_DIR = /mnt/d/cxz/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/cxz/task2/build

# Include any dependencies generated for this target.
include CMakeFiles/SORT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SORT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SORT.dir/flags.make

CMakeFiles/SORT.dir/sort.cpp.o: CMakeFiles/SORT.dir/flags.make
CMakeFiles/SORT.dir/sort.cpp.o: ../sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cxz/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SORT.dir/sort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SORT.dir/sort.cpp.o -c /mnt/d/cxz/task2/sort.cpp

CMakeFiles/SORT.dir/sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SORT.dir/sort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cxz/task2/sort.cpp > CMakeFiles/SORT.dir/sort.cpp.i

CMakeFiles/SORT.dir/sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SORT.dir/sort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cxz/task2/sort.cpp -o CMakeFiles/SORT.dir/sort.cpp.s

# Object files for target SORT
SORT_OBJECTS = \
"CMakeFiles/SORT.dir/sort.cpp.o"

# External object files for target SORT
SORT_EXTERNAL_OBJECTS =

SORT: CMakeFiles/SORT.dir/sort.cpp.o
SORT: CMakeFiles/SORT.dir/build.make
SORT: CMakeFiles/SORT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/cxz/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SORT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SORT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SORT.dir/build: SORT

.PHONY : CMakeFiles/SORT.dir/build

CMakeFiles/SORT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SORT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SORT.dir/clean

CMakeFiles/SORT.dir/depend:
	cd /mnt/d/cxz/task2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/cxz/task2 /mnt/d/cxz/task2 /mnt/d/cxz/task2/build /mnt/d/cxz/task2/build /mnt/d/cxz/task2/build/CMakeFiles/SORT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SORT.dir/depend
