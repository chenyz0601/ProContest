# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /u/halle/chenyua/home_at/Downloads/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /u/halle/chenyua/home_at/Downloads/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Networking.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Networking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Networking.dir/flags.make

CMakeFiles/Networking.dir/main.cpp.o: CMakeFiles/Networking.dir/flags.make
CMakeFiles/Networking.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Networking.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Networking.dir/main.cpp.o -c /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/main.cpp

CMakeFiles/Networking.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Networking.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/main.cpp > CMakeFiles/Networking.dir/main.cpp.i

CMakeFiles/Networking.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Networking.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/main.cpp -o CMakeFiles/Networking.dir/main.cpp.s

CMakeFiles/Networking.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Networking.dir/main.cpp.o.requires

CMakeFiles/Networking.dir/main.cpp.o.provides: CMakeFiles/Networking.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Networking.dir/build.make CMakeFiles/Networking.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Networking.dir/main.cpp.o.provides

CMakeFiles/Networking.dir/main.cpp.o.provides.build: CMakeFiles/Networking.dir/main.cpp.o


# Object files for target Networking
Networking_OBJECTS = \
"CMakeFiles/Networking.dir/main.cpp.o"

# External object files for target Networking
Networking_EXTERNAL_OBJECTS =

Networking: CMakeFiles/Networking.dir/main.cpp.o
Networking: CMakeFiles/Networking.dir/build.make
Networking: CMakeFiles/Networking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Networking"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Networking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Networking.dir/build: Networking

.PHONY : CMakeFiles/Networking.dir/build

CMakeFiles/Networking.dir/requires: CMakeFiles/Networking.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Networking.dir/requires

CMakeFiles/Networking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Networking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Networking.dir/clean

CMakeFiles/Networking.dir/depend:
	cd /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/Networking/cmake-build-debug/CMakeFiles/Networking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Networking.dir/depend

