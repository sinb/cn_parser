# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/hehe/projects/cn_parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hehe/projects/cn_parser/build

# Include any dependencies generated for this target.
include CMakeFiles/cn_parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cn_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cn_parser.dir/flags.make

CMakeFiles/cn_parser.dir/src/main.o: CMakeFiles/cn_parser.dir/flags.make
CMakeFiles/cn_parser.dir/src/main.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hehe/projects/cn_parser/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cn_parser.dir/src/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cn_parser.dir/src/main.o -c /home/hehe/projects/cn_parser/src/main.cpp

CMakeFiles/cn_parser.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cn_parser.dir/src/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hehe/projects/cn_parser/src/main.cpp > CMakeFiles/cn_parser.dir/src/main.i

CMakeFiles/cn_parser.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cn_parser.dir/src/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hehe/projects/cn_parser/src/main.cpp -o CMakeFiles/cn_parser.dir/src/main.s

CMakeFiles/cn_parser.dir/src/main.o.requires:
.PHONY : CMakeFiles/cn_parser.dir/src/main.o.requires

CMakeFiles/cn_parser.dir/src/main.o.provides: CMakeFiles/cn_parser.dir/src/main.o.requires
	$(MAKE) -f CMakeFiles/cn_parser.dir/build.make CMakeFiles/cn_parser.dir/src/main.o.provides.build
.PHONY : CMakeFiles/cn_parser.dir/src/main.o.provides

CMakeFiles/cn_parser.dir/src/main.o.provides.build: CMakeFiles/cn_parser.dir/src/main.o

CMakeFiles/cn_parser.dir/src/DictionaryParser.o: CMakeFiles/cn_parser.dir/flags.make
CMakeFiles/cn_parser.dir/src/DictionaryParser.o: ../src/DictionaryParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hehe/projects/cn_parser/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cn_parser.dir/src/DictionaryParser.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cn_parser.dir/src/DictionaryParser.o -c /home/hehe/projects/cn_parser/src/DictionaryParser.cpp

CMakeFiles/cn_parser.dir/src/DictionaryParser.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cn_parser.dir/src/DictionaryParser.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hehe/projects/cn_parser/src/DictionaryParser.cpp > CMakeFiles/cn_parser.dir/src/DictionaryParser.i

CMakeFiles/cn_parser.dir/src/DictionaryParser.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cn_parser.dir/src/DictionaryParser.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hehe/projects/cn_parser/src/DictionaryParser.cpp -o CMakeFiles/cn_parser.dir/src/DictionaryParser.s

CMakeFiles/cn_parser.dir/src/DictionaryParser.o.requires:
.PHONY : CMakeFiles/cn_parser.dir/src/DictionaryParser.o.requires

CMakeFiles/cn_parser.dir/src/DictionaryParser.o.provides: CMakeFiles/cn_parser.dir/src/DictionaryParser.o.requires
	$(MAKE) -f CMakeFiles/cn_parser.dir/build.make CMakeFiles/cn_parser.dir/src/DictionaryParser.o.provides.build
.PHONY : CMakeFiles/cn_parser.dir/src/DictionaryParser.o.provides

CMakeFiles/cn_parser.dir/src/DictionaryParser.o.provides.build: CMakeFiles/cn_parser.dir/src/DictionaryParser.o

# Object files for target cn_parser
cn_parser_OBJECTS = \
"CMakeFiles/cn_parser.dir/src/main.o" \
"CMakeFiles/cn_parser.dir/src/DictionaryParser.o"

# External object files for target cn_parser
cn_parser_EXTERNAL_OBJECTS =

cn_parser: CMakeFiles/cn_parser.dir/src/main.o
cn_parser: CMakeFiles/cn_parser.dir/src/DictionaryParser.o
cn_parser: CMakeFiles/cn_parser.dir/build.make
cn_parser: CMakeFiles/cn_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cn_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cn_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cn_parser.dir/build: cn_parser
.PHONY : CMakeFiles/cn_parser.dir/build

CMakeFiles/cn_parser.dir/requires: CMakeFiles/cn_parser.dir/src/main.o.requires
CMakeFiles/cn_parser.dir/requires: CMakeFiles/cn_parser.dir/src/DictionaryParser.o.requires
.PHONY : CMakeFiles/cn_parser.dir/requires

CMakeFiles/cn_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cn_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cn_parser.dir/clean

CMakeFiles/cn_parser.dir/depend:
	cd /home/hehe/projects/cn_parser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hehe/projects/cn_parser /home/hehe/projects/cn_parser /home/hehe/projects/cn_parser/build /home/hehe/projects/cn_parser/build /home/hehe/projects/cn_parser/build/CMakeFiles/cn_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cn_parser.dir/depend

