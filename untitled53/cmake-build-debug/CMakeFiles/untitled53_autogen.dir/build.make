# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\eddis\CLionProjects\untitled53

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\eddis\CLionProjects\untitled53\cmake-build-debug

# Utility rule file for untitled53_autogen.

# Include the progress variables for this target.
include CMakeFiles/untitled53_autogen.dir/progress.make

CMakeFiles/untitled53_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\eddis\CLionProjects\untitled53\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target untitled53"
	"C:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/Users/eddis/CLionProjects/untitled53/cmake-build-debug/CMakeFiles/untitled53_autogen.dir/AutogenInfo.json Debug

untitled53_autogen: CMakeFiles/untitled53_autogen
untitled53_autogen: CMakeFiles/untitled53_autogen.dir/build.make

.PHONY : untitled53_autogen

# Rule to build all files generated by this target.
CMakeFiles/untitled53_autogen.dir/build: untitled53_autogen

.PHONY : CMakeFiles/untitled53_autogen.dir/build

CMakeFiles/untitled53_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled53_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled53_autogen.dir/clean

CMakeFiles/untitled53_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\eddis\CLionProjects\untitled53 C:\Users\eddis\CLionProjects\untitled53 C:\Users\eddis\CLionProjects\untitled53\cmake-build-debug C:\Users\eddis\CLionProjects\untitled53\cmake-build-debug C:\Users\eddis\CLionProjects\untitled53\cmake-build-debug\CMakeFiles\untitled53_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled53_autogen.dir/depend

