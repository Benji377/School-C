# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benji/CLionProjects/School-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benji/CLionProjects/School-C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/primZahl.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/primZahl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/primZahl.dir/flags.make

CMakeFiles/primZahl.dir/Fork/primZahl.c.o: CMakeFiles/primZahl.dir/flags.make
CMakeFiles/primZahl.dir/Fork/primZahl.c.o: ../Fork/primZahl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benji/CLionProjects/School-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/primZahl.dir/Fork/primZahl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/primZahl.dir/Fork/primZahl.c.o -c /home/benji/CLionProjects/School-C/Fork/primZahl.c

CMakeFiles/primZahl.dir/Fork/primZahl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/primZahl.dir/Fork/primZahl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/benji/CLionProjects/School-C/Fork/primZahl.c > CMakeFiles/primZahl.dir/Fork/primZahl.c.i

CMakeFiles/primZahl.dir/Fork/primZahl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/primZahl.dir/Fork/primZahl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/benji/CLionProjects/School-C/Fork/primZahl.c -o CMakeFiles/primZahl.dir/Fork/primZahl.c.s

# Object files for target primZahl
primZahl_OBJECTS = \
"CMakeFiles/primZahl.dir/Fork/primZahl.c.o"

# External object files for target primZahl
primZahl_EXTERNAL_OBJECTS =

primZahl: CMakeFiles/primZahl.dir/Fork/primZahl.c.o
primZahl: CMakeFiles/primZahl.dir/build.make
primZahl: CMakeFiles/primZahl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benji/CLionProjects/School-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable primZahl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/primZahl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/primZahl.dir/build: primZahl
.PHONY : CMakeFiles/primZahl.dir/build

CMakeFiles/primZahl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/primZahl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/primZahl.dir/clean

CMakeFiles/primZahl.dir/depend:
	cd /home/benji/CLionProjects/School-C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benji/CLionProjects/School-C /home/benji/CLionProjects/School-C /home/benji/CLionProjects/School-C/cmake-build-debug /home/benji/CLionProjects/School-C/cmake-build-debug /home/benji/CLionProjects/School-C/cmake-build-debug/CMakeFiles/primZahl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/primZahl.dir/depend

