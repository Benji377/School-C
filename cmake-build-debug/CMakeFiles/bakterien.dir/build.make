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
include CMakeFiles/bakterien.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bakterien.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bakterien.dir/flags.make

CMakeFiles/bakterien.dir/matrix/bakterien.c.obj: CMakeFiles/bakterien.dir/flags.make
CMakeFiles/bakterien.dir/matrix/bakterien.c.obj: ../matrix/bakterien.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Coding\C-Projects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bakterien.dir/matrix/bakterien.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bakterien.dir\matrix\bakterien.c.obj -c D:\Coding\C-Projects\matrix\bakterien.c

CMakeFiles/bakterien.dir/matrix/bakterien.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bakterien.dir/matrix/bakterien.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Coding\C-Projects\matrix\bakterien.c > CMakeFiles\bakterien.dir\matrix\bakterien.c.i

CMakeFiles/bakterien.dir/matrix/bakterien.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bakterien.dir/matrix/bakterien.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Coding\C-Projects\matrix\bakterien.c -o CMakeFiles\bakterien.dir\matrix\bakterien.c.s

# Object files for target bakterien
bakterien_OBJECTS = \
"CMakeFiles/bakterien.dir/matrix/bakterien.c.obj"

# External object files for target bakterien
bakterien_EXTERNAL_OBJECTS =

bakterien.exe: CMakeFiles/bakterien.dir/matrix/bakterien.c.obj
bakterien.exe: CMakeFiles/bakterien.dir/build.make
bakterien.exe: CMakeFiles/bakterien.dir/linklibs.rsp
bakterien.exe: CMakeFiles/bakterien.dir/objects1.rsp
bakterien.exe: CMakeFiles/bakterien.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Coding\C-Projects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bakterien.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bakterien.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bakterien.dir/build: bakterien.exe

.PHONY : CMakeFiles/bakterien.dir/build

CMakeFiles/bakterien.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bakterien.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bakterien.dir/clean

CMakeFiles/bakterien.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Coding\C-Projects D:\Coding\C-Projects D:\Coding\C-Projects\cmake-build-debug D:\Coding\C-Projects\cmake-build-debug D:\Coding\C-Projects\cmake-build-debug\CMakeFiles\bakterien.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bakterien.dir/depend

