# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark

# Include any dependencies generated for this target.
include abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/depend.make

# Include the progress variables for this target.
include abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/progress.make

# Include the compile flags for this target's objects.
include abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/flags.make

abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/cord.cc.o: abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/flags.make
abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/cord.cc.o: abseil-cpp/absl/strings/cord.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/cord.cc.o"
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/absl_cord.dir/cord.cc.o -c /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings/cord.cc

abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/cord.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_cord.dir/cord.cc.i"
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings/cord.cc > CMakeFiles/absl_cord.dir/cord.cc.i

abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/cord.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_cord.dir/cord.cc.s"
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings/cord.cc -o CMakeFiles/absl_cord.dir/cord.cc.s

# Object files for target absl_cord
absl_cord_OBJECTS = \
"CMakeFiles/absl_cord.dir/cord.cc.o"

# External object files for target absl_cord
absl_cord_EXTERNAL_OBJECTS =

abseil-cpp/absl/strings/libabsl_cord.a: abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/cord.cc.o
abseil-cpp/absl/strings/libabsl_cord.a: abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/build.make
abseil-cpp/absl/strings/libabsl_cord.a: abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_cord.a"
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings && $(CMAKE_COMMAND) -P CMakeFiles/absl_cord.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/absl_cord.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/build: abseil-cpp/absl/strings/libabsl_cord.a

.PHONY : abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/build

abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/clean:
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings && $(CMAKE_COMMAND) -P CMakeFiles/absl_cord.dir/cmake_clean.cmake
.PHONY : abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/clean

abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/depend:
	cd /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings /mnt/c/Users/MENES/Documents/GitHub/Order-Book-C-HashMap-Benchmark/Benchmark/abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : abseil-cpp/absl/strings/CMakeFiles/absl_cord.dir/depend

