# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ShiftAndExato.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ShiftAndExato.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ShiftAndExato.dir/flags.make

CMakeFiles/ShiftAndExato.dir/main.c.obj: CMakeFiles/ShiftAndExato.dir/flags.make
CMakeFiles/ShiftAndExato.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ShiftAndExato.dir/main.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ShiftAndExato.dir\main.c.obj   -c "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\main.c"

CMakeFiles/ShiftAndExato.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ShiftAndExato.dir/main.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\main.c" > CMakeFiles\ShiftAndExato.dir\main.c.i

CMakeFiles/ShiftAndExato.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ShiftAndExato.dir/main.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\main.c" -o CMakeFiles\ShiftAndExato.dir\main.c.s

CMakeFiles/ShiftAndExato.dir/shif.c.obj: CMakeFiles/ShiftAndExato.dir/flags.make
CMakeFiles/ShiftAndExato.dir/shif.c.obj: ../shif.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ShiftAndExato.dir/shif.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ShiftAndExato.dir\shif.c.obj   -c "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\shif.c"

CMakeFiles/ShiftAndExato.dir/shif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ShiftAndExato.dir/shif.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\shif.c" > CMakeFiles\ShiftAndExato.dir\shif.c.i

CMakeFiles/ShiftAndExato.dir/shif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ShiftAndExato.dir/shif.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\shif.c" -o CMakeFiles\ShiftAndExato.dir\shif.c.s

# Object files for target ShiftAndExato
ShiftAndExato_OBJECTS = \
"CMakeFiles/ShiftAndExato.dir/main.c.obj" \
"CMakeFiles/ShiftAndExato.dir/shif.c.obj"

# External object files for target ShiftAndExato
ShiftAndExato_EXTERNAL_OBJECTS =

ShiftAndExato.exe: CMakeFiles/ShiftAndExato.dir/main.c.obj
ShiftAndExato.exe: CMakeFiles/ShiftAndExato.dir/shif.c.obj
ShiftAndExato.exe: CMakeFiles/ShiftAndExato.dir/build.make
ShiftAndExato.exe: CMakeFiles/ShiftAndExato.dir/linklibs.rsp
ShiftAndExato.exe: CMakeFiles/ShiftAndExato.dir/objects1.rsp
ShiftAndExato.exe: CMakeFiles/ShiftAndExato.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ShiftAndExato.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ShiftAndExato.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ShiftAndExato.dir/build: ShiftAndExato.exe

.PHONY : CMakeFiles/ShiftAndExato.dir/build

CMakeFiles/ShiftAndExato.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ShiftAndExato.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ShiftAndExato.dir/clean

CMakeFiles/ShiftAndExato.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\ShiftAndExato\cmake-build-debug\CMakeFiles\ShiftAndExato.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ShiftAndExato.dir/depend
