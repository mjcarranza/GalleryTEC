# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abner/Desktop/GalleryTEC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abner/Desktop/GalleryTEC/cmake-build-debug

# Utility rule file for GalleryTEC_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/GalleryTEC_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GalleryTEC_autogen.dir/progress.make

CMakeFiles/GalleryTEC_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/abner/Desktop/GalleryTEC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target GalleryTEC"
	/snap/clion/169/bin/cmake/linux/bin/cmake -E cmake_autogen /home/abner/Desktop/GalleryTEC/cmake-build-debug/CMakeFiles/GalleryTEC_autogen.dir/AutogenInfo.json Debug

GalleryTEC_autogen: CMakeFiles/GalleryTEC_autogen
GalleryTEC_autogen: CMakeFiles/GalleryTEC_autogen.dir/build.make
.PHONY : GalleryTEC_autogen

# Rule to build all files generated by this target.
CMakeFiles/GalleryTEC_autogen.dir/build: GalleryTEC_autogen
.PHONY : CMakeFiles/GalleryTEC_autogen.dir/build

CMakeFiles/GalleryTEC_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GalleryTEC_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GalleryTEC_autogen.dir/clean

CMakeFiles/GalleryTEC_autogen.dir/depend:
	cd /home/abner/Desktop/GalleryTEC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abner/Desktop/GalleryTEC /home/abner/Desktop/GalleryTEC /home/abner/Desktop/GalleryTEC/cmake-build-debug /home/abner/Desktop/GalleryTEC/cmake-build-debug /home/abner/Desktop/GalleryTEC/cmake-build-debug/CMakeFiles/GalleryTEC_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GalleryTEC_autogen.dir/depend
