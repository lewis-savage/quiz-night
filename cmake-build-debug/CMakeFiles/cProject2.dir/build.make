# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lewis\CLionProjects\cProject2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lewis\CLionProjects\cProject2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cProject2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cProject2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cProject2.dir/flags.make

CMakeFiles/cProject2.dir/main.c.obj: CMakeFiles/cProject2.dir/flags.make
CMakeFiles/cProject2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lewis\CLionProjects\cProject2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cProject2.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cProject2.dir\main.c.obj   -c C:\Users\lewis\CLionProjects\cProject2\main.c

CMakeFiles/cProject2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cProject2.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lewis\CLionProjects\cProject2\main.c > CMakeFiles\cProject2.dir\main.c.i

CMakeFiles/cProject2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cProject2.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lewis\CLionProjects\cProject2\main.c -o CMakeFiles\cProject2.dir\main.c.s

# Object files for target cProject2
cProject2_OBJECTS = \
"CMakeFiles/cProject2.dir/main.c.obj"

# External object files for target cProject2
cProject2_EXTERNAL_OBJECTS =

cProject2.exe: CMakeFiles/cProject2.dir/main.c.obj
cProject2.exe: CMakeFiles/cProject2.dir/build.make
cProject2.exe: CMakeFiles/cProject2.dir/linklibs.rsp
cProject2.exe: CMakeFiles/cProject2.dir/objects1.rsp
cProject2.exe: CMakeFiles/cProject2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lewis\CLionProjects\cProject2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cProject2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cProject2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cProject2.dir/build: cProject2.exe

.PHONY : CMakeFiles/cProject2.dir/build

CMakeFiles/cProject2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cProject2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cProject2.dir/clean

CMakeFiles/cProject2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lewis\CLionProjects\cProject2 C:\Users\lewis\CLionProjects\cProject2 C:\Users\lewis\CLionProjects\cProject2\cmake-build-debug C:\Users\lewis\CLionProjects\cProject2\cmake-build-debug C:\Users\lewis\CLionProjects\cProject2\cmake-build-debug\CMakeFiles\cProject2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cProject2.dir/depend

