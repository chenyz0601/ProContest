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
CMAKE_SOURCE_DIR = /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TravelTrouble.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TravelTrouble.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TravelTrouble.dir/flags.make

CMakeFiles/TravelTrouble.dir/main.cpp.o: CMakeFiles/TravelTrouble.dir/flags.make
CMakeFiles/TravelTrouble.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TravelTrouble.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TravelTrouble.dir/main.cpp.o -c /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/main.cpp

CMakeFiles/TravelTrouble.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TravelTrouble.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/main.cpp > CMakeFiles/TravelTrouble.dir/main.cpp.i

CMakeFiles/TravelTrouble.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TravelTrouble.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/main.cpp -o CMakeFiles/TravelTrouble.dir/main.cpp.s

CMakeFiles/TravelTrouble.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TravelTrouble.dir/main.cpp.o.requires

CMakeFiles/TravelTrouble.dir/main.cpp.o.provides: CMakeFiles/TravelTrouble.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TravelTrouble.dir/build.make CMakeFiles/TravelTrouble.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TravelTrouble.dir/main.cpp.o.provides

CMakeFiles/TravelTrouble.dir/main.cpp.o.provides.build: CMakeFiles/TravelTrouble.dir/main.cpp.o


# Object files for target TravelTrouble
TravelTrouble_OBJECTS = \
"CMakeFiles/TravelTrouble.dir/main.cpp.o"

# External object files for target TravelTrouble
TravelTrouble_EXTERNAL_OBJECTS =

TravelTrouble: CMakeFiles/TravelTrouble.dir/main.cpp.o
TravelTrouble: CMakeFiles/TravelTrouble.dir/build.make
TravelTrouble: CMakeFiles/TravelTrouble.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TravelTrouble"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TravelTrouble.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TravelTrouble.dir/build: TravelTrouble

.PHONY : CMakeFiles/TravelTrouble.dir/build

CMakeFiles/TravelTrouble.dir/requires: CMakeFiles/TravelTrouble.dir/main.cpp.o.requires

.PHONY : CMakeFiles/TravelTrouble.dir/requires

CMakeFiles/TravelTrouble.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TravelTrouble.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TravelTrouble.dir/clean

CMakeFiles/TravelTrouble.dir/depend:
	cd /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug /u/halle/chenyua/home_at/Downloads/SS16-17/ProContest/sheet3/TravelTrouble/cmake-build-debug/CMakeFiles/TravelTrouble.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TravelTrouble.dir/depend
