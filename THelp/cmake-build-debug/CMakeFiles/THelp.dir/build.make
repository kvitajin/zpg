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
CMAKE_COMMAND = /home/kvitajin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.18/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kvitajin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.18/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kvitajin/CLionProjects/vsb/zpg/THelp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/THelp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/THelp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/THelp.dir/flags.make

CMakeFiles/THelp.dir/main.cpp.o: CMakeFiles/THelp.dir/flags.make
CMakeFiles/THelp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/THelp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/THelp.dir/main.cpp.o -c /home/kvitajin/CLionProjects/vsb/zpg/THelp/main.cpp

CMakeFiles/THelp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/THelp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kvitajin/CLionProjects/vsb/zpg/THelp/main.cpp > CMakeFiles/THelp.dir/main.cpp.i

CMakeFiles/THelp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/THelp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kvitajin/CLionProjects/vsb/zpg/THelp/main.cpp -o CMakeFiles/THelp.dir/main.cpp.s

# Object files for target THelp
THelp_OBJECTS = \
"CMakeFiles/THelp.dir/main.cpp.o"

# External object files for target THelp
THelp_EXTERNAL_OBJECTS =

THelp: CMakeFiles/THelp.dir/main.cpp.o
THelp: CMakeFiles/THelp.dir/build.make
THelp: CMakeFiles/THelp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable THelp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/THelp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/THelp.dir/build: THelp

.PHONY : CMakeFiles/THelp.dir/build

CMakeFiles/THelp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/THelp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/THelp.dir/clean

CMakeFiles/THelp.dir/depend:
	cd /home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kvitajin/CLionProjects/vsb/zpg/THelp /home/kvitajin/CLionProjects/vsb/zpg/THelp /home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug /home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug /home/kvitajin/CLionProjects/vsb/zpg/THelp/cmake-build-debug/CMakeFiles/THelp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/THelp.dir/depend

