# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/teo/repos/lpinel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teo/repos/lpinel/build

# Include any dependencies generated for this target.
include libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/depend.make

# Include the progress variables for this target.
include libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/flags.make

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/flags.make
libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o: ../libraries/ExampleLibrary/ExampleLibrary.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/teo/repos/lpinel/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o"
	cd /home/teo/repos/lpinel/build/libraries/ExampleLibrary && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o -c /home/teo/repos/lpinel/libraries/ExampleLibrary/ExampleLibrary.cpp

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.i"
	cd /home/teo/repos/lpinel/build/libraries/ExampleLibrary && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/teo/repos/lpinel/libraries/ExampleLibrary/ExampleLibrary.cpp > CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.i

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.s"
	cd /home/teo/repos/lpinel/build/libraries/ExampleLibrary && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/teo/repos/lpinel/libraries/ExampleLibrary/ExampleLibrary.cpp -o CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.s

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.requires:
.PHONY : libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.requires

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.provides: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.requires
	$(MAKE) -f libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/build.make libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.provides.build
.PHONY : libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.provides

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.provides.build: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o

# Object files for target ExampleLibrary
ExampleLibrary_OBJECTS = \
"CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o"

# External object files for target ExampleLibrary
ExampleLibrary_EXTERNAL_OBJECTS =

lib/libExampleLibrary.a: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o
lib/libExampleLibrary.a: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/build.make
lib/libExampleLibrary.a: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libExampleLibrary.a"
	cd /home/teo/repos/lpinel/build/libraries/ExampleLibrary && $(CMAKE_COMMAND) -P CMakeFiles/ExampleLibrary.dir/cmake_clean_target.cmake
	cd /home/teo/repos/lpinel/build/libraries/ExampleLibrary && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExampleLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/build: lib/libExampleLibrary.a
.PHONY : libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/build

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/requires: libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/ExampleLibrary.cpp.o.requires
.PHONY : libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/requires

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/clean:
	cd /home/teo/repos/lpinel/build/libraries/ExampleLibrary && $(CMAKE_COMMAND) -P CMakeFiles/ExampleLibrary.dir/cmake_clean.cmake
.PHONY : libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/clean

libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/depend:
	cd /home/teo/repos/lpinel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teo/repos/lpinel /home/teo/repos/lpinel/libraries/ExampleLibrary /home/teo/repos/lpinel/build /home/teo/repos/lpinel/build/libraries/ExampleLibrary /home/teo/repos/lpinel/build/libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libraries/ExampleLibrary/CMakeFiles/ExampleLibrary.dir/depend

