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
CMAKE_SOURCE_DIR = "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TP4_PAA_KMP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP4_PAA_KMP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP4_PAA_KMP.dir/flags.make

CMakeFiles/TP4_PAA_KMP.dir/main.c.obj: CMakeFiles/TP4_PAA_KMP.dir/flags.make
CMakeFiles/TP4_PAA_KMP.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP4_PAA_KMP.dir/main.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP4_PAA_KMP.dir\main.c.obj   -c "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\main.c"

CMakeFiles/TP4_PAA_KMP.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP4_PAA_KMP.dir/main.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\main.c" > CMakeFiles\TP4_PAA_KMP.dir\main.c.i

CMakeFiles/TP4_PAA_KMP.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP4_PAA_KMP.dir/main.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\main.c" -o CMakeFiles\TP4_PAA_KMP.dir\main.c.s

CMakeFiles/TP4_PAA_KMP.dir/KMP.c.obj: CMakeFiles/TP4_PAA_KMP.dir/flags.make
CMakeFiles/TP4_PAA_KMP.dir/KMP.c.obj: ../KMP.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TP4_PAA_KMP.dir/KMP.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP4_PAA_KMP.dir\KMP.c.obj   -c "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\KMP.c"

CMakeFiles/TP4_PAA_KMP.dir/KMP.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP4_PAA_KMP.dir/KMP.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\KMP.c" > CMakeFiles\TP4_PAA_KMP.dir\KMP.c.i

CMakeFiles/TP4_PAA_KMP.dir/KMP.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP4_PAA_KMP.dir/KMP.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\KMP.c" -o CMakeFiles\TP4_PAA_KMP.dir\KMP.c.s

# Object files for target TP4_PAA_KMP
TP4_PAA_KMP_OBJECTS = \
"CMakeFiles/TP4_PAA_KMP.dir/main.c.obj" \
"CMakeFiles/TP4_PAA_KMP.dir/KMP.c.obj"

# External object files for target TP4_PAA_KMP
TP4_PAA_KMP_EXTERNAL_OBJECTS =

TP4_PAA_KMP.exe: CMakeFiles/TP4_PAA_KMP.dir/main.c.obj
TP4_PAA_KMP.exe: CMakeFiles/TP4_PAA_KMP.dir/KMP.c.obj
TP4_PAA_KMP.exe: CMakeFiles/TP4_PAA_KMP.dir/build.make
TP4_PAA_KMP.exe: CMakeFiles/TP4_PAA_KMP.dir/linklibs.rsp
TP4_PAA_KMP.exe: CMakeFiles/TP4_PAA_KMP.dir/objects1.rsp
TP4_PAA_KMP.exe: CMakeFiles/TP4_PAA_KMP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable TP4_PAA_KMP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TP4_PAA_KMP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP4_PAA_KMP.dir/build: TP4_PAA_KMP.exe

.PHONY : CMakeFiles/TP4_PAA_KMP.dir/build

CMakeFiles/TP4_PAA_KMP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TP4_PAA_KMP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TP4_PAA_KMP.dir/clean

CMakeFiles/TP4_PAA_KMP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug" "C:\Users\vho20\Dropbox\facu\4 SEMESTRE\PAA\TPS\TP4\TP4_PAA_KMP\cmake-build-debug\CMakeFiles\TP4_PAA_KMP.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TP4_PAA_KMP.dir/depend

