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
CMAKE_SOURCE_DIR = /home/oslab/Desktop/C++/projects/project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oslab/Desktop/C++/projects/project2

# Include any dependencies generated for this target.
include CMakeFiles/project2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project2.dir/flags.make

CMakeFiles/project2.dir/src/functions.cpp.o: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/src/functions.cpp.o: src/functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oslab/Desktop/C++/projects/project2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project2.dir/src/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project2.dir/src/functions.cpp.o -c /home/oslab/Desktop/C++/projects/project2/src/functions.cpp

CMakeFiles/project2.dir/src/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project2.dir/src/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oslab/Desktop/C++/projects/project2/src/functions.cpp > CMakeFiles/project2.dir/src/functions.cpp.i

CMakeFiles/project2.dir/src/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project2.dir/src/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oslab/Desktop/C++/projects/project2/src/functions.cpp -o CMakeFiles/project2.dir/src/functions.cpp.s

CMakeFiles/project2.dir/src/instructions.cpp.o: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/src/instructions.cpp.o: src/instructions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oslab/Desktop/C++/projects/project2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project2.dir/src/instructions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project2.dir/src/instructions.cpp.o -c /home/oslab/Desktop/C++/projects/project2/src/instructions.cpp

CMakeFiles/project2.dir/src/instructions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project2.dir/src/instructions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oslab/Desktop/C++/projects/project2/src/instructions.cpp > CMakeFiles/project2.dir/src/instructions.cpp.i

CMakeFiles/project2.dir/src/instructions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project2.dir/src/instructions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oslab/Desktop/C++/projects/project2/src/instructions.cpp -o CMakeFiles/project2.dir/src/instructions.cpp.s

CMakeFiles/project2.dir/src/main.cpp.o: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oslab/Desktop/C++/projects/project2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project2.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project2.dir/src/main.cpp.o -c /home/oslab/Desktop/C++/projects/project2/src/main.cpp

CMakeFiles/project2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project2.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oslab/Desktop/C++/projects/project2/src/main.cpp > CMakeFiles/project2.dir/src/main.cpp.i

CMakeFiles/project2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project2.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oslab/Desktop/C++/projects/project2/src/main.cpp -o CMakeFiles/project2.dir/src/main.cpp.s

# Object files for target project2
project2_OBJECTS = \
"CMakeFiles/project2.dir/src/functions.cpp.o" \
"CMakeFiles/project2.dir/src/instructions.cpp.o" \
"CMakeFiles/project2.dir/src/main.cpp.o"

# External object files for target project2
project2_EXTERNAL_OBJECTS =

project2: CMakeFiles/project2.dir/src/functions.cpp.o
project2: CMakeFiles/project2.dir/src/instructions.cpp.o
project2: CMakeFiles/project2.dir/src/main.cpp.o
project2: CMakeFiles/project2.dir/build.make
project2: CMakeFiles/project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oslab/Desktop/C++/projects/project2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable project2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project2.dir/build: project2

.PHONY : CMakeFiles/project2.dir/build

CMakeFiles/project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project2.dir/clean

CMakeFiles/project2.dir/depend:
	cd /home/oslab/Desktop/C++/projects/project2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oslab/Desktop/C++/projects/project2 /home/oslab/Desktop/C++/projects/project2 /home/oslab/Desktop/C++/projects/project2 /home/oslab/Desktop/C++/projects/project2 /home/oslab/Desktop/C++/projects/project2/CMakeFiles/project2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project2.dir/depend

