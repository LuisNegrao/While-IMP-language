# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/178/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/178/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luis/Faculdade/5ano/While-IMP-language

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linguagem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linguagem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linguagem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linguagem.dir/flags.make

CMakeFiles/linguagem.dir/main.c.o: CMakeFiles/linguagem.dir/flags.make
CMakeFiles/linguagem.dir/main.c.o: ../main.c
CMakeFiles/linguagem.dir/main.c.o: CMakeFiles/linguagem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linguagem.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/linguagem.dir/main.c.o -MF CMakeFiles/linguagem.dir/main.c.o.d -o CMakeFiles/linguagem.dir/main.c.o -c /home/luis/Faculdade/5ano/While-IMP-language/main.c

CMakeFiles/linguagem.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linguagem.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/luis/Faculdade/5ano/While-IMP-language/main.c > CMakeFiles/linguagem.dir/main.c.i

CMakeFiles/linguagem.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linguagem.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/luis/Faculdade/5ano/While-IMP-language/main.c -o CMakeFiles/linguagem.dir/main.c.s

CMakeFiles/linguagem.dir/language.c.o: CMakeFiles/linguagem.dir/flags.make
CMakeFiles/linguagem.dir/language.c.o: ../language.c
CMakeFiles/linguagem.dir/language.c.o: CMakeFiles/linguagem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/linguagem.dir/language.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/linguagem.dir/language.c.o -MF CMakeFiles/linguagem.dir/language.c.o.d -o CMakeFiles/linguagem.dir/language.c.o -c /home/luis/Faculdade/5ano/While-IMP-language/language.c

CMakeFiles/linguagem.dir/language.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linguagem.dir/language.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/luis/Faculdade/5ano/While-IMP-language/language.c > CMakeFiles/linguagem.dir/language.c.i

CMakeFiles/linguagem.dir/language.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linguagem.dir/language.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/luis/Faculdade/5ano/While-IMP-language/language.c -o CMakeFiles/linguagem.dir/language.c.s

CMakeFiles/linguagem.dir/runner.c.o: CMakeFiles/linguagem.dir/flags.make
CMakeFiles/linguagem.dir/runner.c.o: ../runner.c
CMakeFiles/linguagem.dir/runner.c.o: CMakeFiles/linguagem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/linguagem.dir/runner.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/linguagem.dir/runner.c.o -MF CMakeFiles/linguagem.dir/runner.c.o.d -o CMakeFiles/linguagem.dir/runner.c.o -c /home/luis/Faculdade/5ano/While-IMP-language/runner.c

CMakeFiles/linguagem.dir/runner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linguagem.dir/runner.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/luis/Faculdade/5ano/While-IMP-language/runner.c > CMakeFiles/linguagem.dir/runner.c.i

CMakeFiles/linguagem.dir/runner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linguagem.dir/runner.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/luis/Faculdade/5ano/While-IMP-language/runner.c -o CMakeFiles/linguagem.dir/runner.c.s

# Object files for target linguagem
linguagem_OBJECTS = \
"CMakeFiles/linguagem.dir/main.c.o" \
"CMakeFiles/linguagem.dir/language.c.o" \
"CMakeFiles/linguagem.dir/runner.c.o"

# External object files for target linguagem
linguagem_EXTERNAL_OBJECTS =

linguagem: CMakeFiles/linguagem.dir/main.c.o
linguagem: CMakeFiles/linguagem.dir/language.c.o
linguagem: CMakeFiles/linguagem.dir/runner.c.o
linguagem: CMakeFiles/linguagem.dir/build.make
linguagem: CMakeFiles/linguagem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable linguagem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linguagem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linguagem.dir/build: linguagem
.PHONY : CMakeFiles/linguagem.dir/build

CMakeFiles/linguagem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linguagem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linguagem.dir/clean

CMakeFiles/linguagem.dir/depend:
	cd /home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/Faculdade/5ano/While-IMP-language /home/luis/Faculdade/5ano/While-IMP-language /home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug /home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug /home/luis/Faculdade/5ano/While-IMP-language/cmake-build-debug/CMakeFiles/linguagem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linguagem.dir/depend

