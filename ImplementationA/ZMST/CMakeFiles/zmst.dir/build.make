# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/badpoet/epsilons/qt-training/solveRST/ImplementationA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/badpoet/epsilons/qt-training/solveRST/ImplementationA

# Include any dependencies generated for this target.
include ZMST/CMakeFiles/zmst.dir/depend.make

# Include the progress variables for this target.
include ZMST/CMakeFiles/zmst.dir/progress.make

# Include the compile flags for this target's objects.
include ZMST/CMakeFiles/zmst.dir/flags.make

ZMST/CMakeFiles/zmst.dir/main.o: ZMST/CMakeFiles/zmst.dir/flags.make
ZMST/CMakeFiles/zmst.dir/main.o: ZMST/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object ZMST/CMakeFiles/zmst.dir/main.o"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zmst.dir/main.o -c /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/main.cpp

ZMST/CMakeFiles/zmst.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmst.dir/main.i"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/main.cpp > CMakeFiles/zmst.dir/main.i

ZMST/CMakeFiles/zmst.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmst.dir/main.s"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/main.cpp -o CMakeFiles/zmst.dir/main.s

ZMST/CMakeFiles/zmst.dir/main.o.requires:
.PHONY : ZMST/CMakeFiles/zmst.dir/main.o.requires

ZMST/CMakeFiles/zmst.dir/main.o.provides: ZMST/CMakeFiles/zmst.dir/main.o.requires
	$(MAKE) -f ZMST/CMakeFiles/zmst.dir/build.make ZMST/CMakeFiles/zmst.dir/main.o.provides.build
.PHONY : ZMST/CMakeFiles/zmst.dir/main.o.provides

ZMST/CMakeFiles/zmst.dir/main.o.provides.build: ZMST/CMakeFiles/zmst.dir/main.o

ZMST/CMakeFiles/zmst.dir/ZMST.o: ZMST/CMakeFiles/zmst.dir/flags.make
ZMST/CMakeFiles/zmst.dir/ZMST.o: ZMST/ZMST.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object ZMST/CMakeFiles/zmst.dir/ZMST.o"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zmst.dir/ZMST.o -c /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/ZMST.cpp

ZMST/CMakeFiles/zmst.dir/ZMST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmst.dir/ZMST.i"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/ZMST.cpp > CMakeFiles/zmst.dir/ZMST.i

ZMST/CMakeFiles/zmst.dir/ZMST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmst.dir/ZMST.s"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/ZMST.cpp -o CMakeFiles/zmst.dir/ZMST.s

ZMST/CMakeFiles/zmst.dir/ZMST.o.requires:
.PHONY : ZMST/CMakeFiles/zmst.dir/ZMST.o.requires

ZMST/CMakeFiles/zmst.dir/ZMST.o.provides: ZMST/CMakeFiles/zmst.dir/ZMST.o.requires
	$(MAKE) -f ZMST/CMakeFiles/zmst.dir/build.make ZMST/CMakeFiles/zmst.dir/ZMST.o.provides.build
.PHONY : ZMST/CMakeFiles/zmst.dir/ZMST.o.provides

ZMST/CMakeFiles/zmst.dir/ZMST.o.provides.build: ZMST/CMakeFiles/zmst.dir/ZMST.o

ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o: ZMST/CMakeFiles/zmst.dir/flags.make
ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o: SMST/PointsGenerator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o -c /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/SMST/PointsGenerator.cpp

ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmst.dir/__/SMST/PointsGenerator.i"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/SMST/PointsGenerator.cpp > CMakeFiles/zmst.dir/__/SMST/PointsGenerator.i

ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmst.dir/__/SMST/PointsGenerator.s"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/SMST/PointsGenerator.cpp -o CMakeFiles/zmst.dir/__/SMST/PointsGenerator.s

ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.requires:
.PHONY : ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.requires

ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.provides: ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.requires
	$(MAKE) -f ZMST/CMakeFiles/zmst.dir/build.make ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.provides.build
.PHONY : ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.provides

ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.provides.build: ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o

ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o: ZMST/CMakeFiles/zmst.dir/flags.make
ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o: SMST/SMST.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zmst.dir/__/SMST/SMST.o -c /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/SMST/SMST.cpp

ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmst.dir/__/SMST/SMST.i"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/SMST/SMST.cpp > CMakeFiles/zmst.dir/__/SMST/SMST.i

ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmst.dir/__/SMST/SMST.s"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/SMST/SMST.cpp -o CMakeFiles/zmst.dir/__/SMST/SMST.s

ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.requires:
.PHONY : ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.requires

ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.provides: ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.requires
	$(MAKE) -f ZMST/CMakeFiles/zmst.dir/build.make ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.provides.build
.PHONY : ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.provides

ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.provides.build: ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o

# Object files for target zmst
zmst_OBJECTS = \
"CMakeFiles/zmst.dir/main.o" \
"CMakeFiles/zmst.dir/ZMST.o" \
"CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o" \
"CMakeFiles/zmst.dir/__/SMST/SMST.o"

# External object files for target zmst
zmst_EXTERNAL_OBJECTS =

bin/zmst: ZMST/CMakeFiles/zmst.dir/main.o
bin/zmst: ZMST/CMakeFiles/zmst.dir/ZMST.o
bin/zmst: ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o
bin/zmst: ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o
bin/zmst: ZMST/CMakeFiles/zmst.dir/build.make
bin/zmst: ZMST/CMakeFiles/zmst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/zmst"
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ZMST/CMakeFiles/zmst.dir/build: bin/zmst
.PHONY : ZMST/CMakeFiles/zmst.dir/build

ZMST/CMakeFiles/zmst.dir/requires: ZMST/CMakeFiles/zmst.dir/main.o.requires
ZMST/CMakeFiles/zmst.dir/requires: ZMST/CMakeFiles/zmst.dir/ZMST.o.requires
ZMST/CMakeFiles/zmst.dir/requires: ZMST/CMakeFiles/zmst.dir/__/SMST/PointsGenerator.o.requires
ZMST/CMakeFiles/zmst.dir/requires: ZMST/CMakeFiles/zmst.dir/__/SMST/SMST.o.requires
.PHONY : ZMST/CMakeFiles/zmst.dir/requires

ZMST/CMakeFiles/zmst.dir/clean:
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST && $(CMAKE_COMMAND) -P CMakeFiles/zmst.dir/cmake_clean.cmake
.PHONY : ZMST/CMakeFiles/zmst.dir/clean

ZMST/CMakeFiles/zmst.dir/depend:
	cd /home/badpoet/epsilons/qt-training/solveRST/ImplementationA && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/badpoet/epsilons/qt-training/solveRST/ImplementationA /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST /home/badpoet/epsilons/qt-training/solveRST/ImplementationA /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST /home/badpoet/epsilons/qt-training/solveRST/ImplementationA/ZMST/CMakeFiles/zmst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ZMST/CMakeFiles/zmst.dir/depend
