# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/kvitajin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kvitajin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kvitajin/CLionProjects/vsb/zpg/navod

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/navod.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/navod.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/navod.dir/flags.make

CMakeFiles/navod.dir/files/main.cpp.o: CMakeFiles/navod.dir/flags.make
CMakeFiles/navod.dir/files/main.cpp.o: ../files/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/navod.dir/files/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/navod.dir/files/main.cpp.o -c /home/kvitajin/CLionProjects/vsb/zpg/navod/files/main.cpp

CMakeFiles/navod.dir/files/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navod.dir/files/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kvitajin/CLionProjects/vsb/zpg/navod/files/main.cpp > CMakeFiles/navod.dir/files/main.cpp.i

CMakeFiles/navod.dir/files/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navod.dir/files/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kvitajin/CLionProjects/vsb/zpg/navod/files/main.cpp -o CMakeFiles/navod.dir/files/main.cpp.s

# Object files for target navod
navod_OBJECTS = \
"CMakeFiles/navod.dir/files/main.cpp.o"

# External object files for target navod
navod_EXTERNAL_OBJECTS =

navod: CMakeFiles/navod.dir/files/main.cpp.o
navod: CMakeFiles/navod.dir/build.make
navod: CMakeFiles/navod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable navod"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/navod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/navod.dir/build: navod

.PHONY : CMakeFiles/navod.dir/build

CMakeFiles/navod.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/navod.dir/cmake_clean.cmake
.PHONY : CMakeFiles/navod.dir/clean

CMakeFiles/navod.dir/depend:
	cd /home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kvitajin/CLionProjects/vsb/zpg/navod /home/kvitajin/CLionProjects/vsb/zpg/navod /home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug /home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug /home/kvitajin/CLionProjects/vsb/zpg/navod/cmake-build-debug/CMakeFiles/navod.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/navod.dir/depend

