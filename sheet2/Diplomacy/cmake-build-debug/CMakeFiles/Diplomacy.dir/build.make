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
CMAKE_COMMAND = /cygdrive/c/Users/Yuanze/.CLion2017.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Yuanze/.CLion2017.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Diplomacy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Diplomacy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Diplomacy.dir/flags.make

CMakeFiles/Diplomacy.dir/main.cpp.o: CMakeFiles/Diplomacy.dir/flags.make
CMakeFiles/Diplomacy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Diplomacy.dir/main.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Diplomacy.dir/main.cpp.o -c /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/main.cpp

CMakeFiles/Diplomacy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Diplomacy.dir/main.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/main.cpp > CMakeFiles/Diplomacy.dir/main.cpp.i

CMakeFiles/Diplomacy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Diplomacy.dir/main.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/main.cpp -o CMakeFiles/Diplomacy.dir/main.cpp.s

CMakeFiles/Diplomacy.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Diplomacy.dir/main.cpp.o.requires

CMakeFiles/Diplomacy.dir/main.cpp.o.provides: CMakeFiles/Diplomacy.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Diplomacy.dir/build.make CMakeFiles/Diplomacy.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Diplomacy.dir/main.cpp.o.provides

CMakeFiles/Diplomacy.dir/main.cpp.o.provides.build: CMakeFiles/Diplomacy.dir/main.cpp.o


# Object files for target Diplomacy
Diplomacy_OBJECTS = \
"CMakeFiles/Diplomacy.dir/main.cpp.o"

# External object files for target Diplomacy
Diplomacy_EXTERNAL_OBJECTS =

Diplomacy.exe: CMakeFiles/Diplomacy.dir/main.cpp.o
Diplomacy.exe: CMakeFiles/Diplomacy.dir/build.make
Diplomacy.exe: CMakeFiles/Diplomacy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Diplomacy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Diplomacy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Diplomacy.dir/build: Diplomacy.exe

.PHONY : CMakeFiles/Diplomacy.dir/build

CMakeFiles/Diplomacy.dir/requires: CMakeFiles/Diplomacy.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Diplomacy.dir/requires

CMakeFiles/Diplomacy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Diplomacy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Diplomacy.dir/clean

CMakeFiles/Diplomacy.dir/depend:
	cd /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug /cygdrive/c/Users/Yuanze/CLionProjects/Diplomacy/cmake-build-debug/CMakeFiles/Diplomacy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Diplomacy.dir/depend
