# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\benbe\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7142.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\benbe\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7142.21\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Coding\C-Projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Coding\C-Projects\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rekursive_fibonacci.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rekursive_fibonacci.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rekursive_fibonacci.dir/flags.make

CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.obj: CMakeFiles/rekursive_fibonacci.dir/flags.make
CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.obj: ../rekursiv/rekursive_fibonacci.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Coding\C-Projects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\rekursive_fibonacci.dir\rekursiv\rekursive_fibonacci.c.obj -c D:\Coding\C-Projects\rekursiv\rekursive_fibonacci.c

CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Coding\C-Projects\rekursiv\rekursive_fibonacci.c > CMakeFiles\rekursive_fibonacci.dir\rekursiv\rekursive_fibonacci.c.i

CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Coding\C-Projects\rekursiv\rekursive_fibonacci.c -o CMakeFiles\rekursive_fibonacci.dir\rekursiv\rekursive_fibonacci.c.s

# Object files for target rekursive_fibonacci
rekursive_fibonacci_OBJECTS = \
"CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.obj"

# External object files for target rekursive_fibonacci
rekursive_fibonacci_EXTERNAL_OBJECTS =

rekursive_fibonacci.exe: CMakeFiles/rekursive_fibonacci.dir/rekursiv/rekursive_fibonacci.c.obj
rekursive_fibonacci.exe: CMakeFiles/rekursive_fibonacci.dir/build.make
rekursive_fibonacci.exe: CMakeFiles/rekursive_fibonacci.dir/linklibs.rsp
rekursive_fibonacci.exe: CMakeFiles/rekursive_fibonacci.dir/objects1.rsp
rekursive_fibonacci.exe: CMakeFiles/rekursive_fibonacci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Coding\C-Projects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rekursive_fibonacci.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rekursive_fibonacci.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rekursive_fibonacci.dir/build: rekursive_fibonacci.exe

.PHONY : CMakeFiles/rekursive_fibonacci.dir/build

CMakeFiles/rekursive_fibonacci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rekursive_fibonacci.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rekursive_fibonacci.dir/clean

CMakeFiles/rekursive_fibonacci.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Coding\C-Projects D:\Coding\C-Projects D:\Coding\C-Projects\cmake-build-debug D:\Coding\C-Projects\cmake-build-debug D:\Coding\C-Projects\cmake-build-debug\CMakeFiles\rekursive_fibonacci.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rekursive_fibonacci.dir/depend

