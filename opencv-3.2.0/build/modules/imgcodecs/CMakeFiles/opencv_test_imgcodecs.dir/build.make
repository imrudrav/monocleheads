# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build

# Include any dependencies generated for this target.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/depend.make

# Include the progress variables for this target.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/progress.make

# Include the compile flags for this target's objects.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o: ../modules/imgcodecs/test/test_grfmt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o -c /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs/test/test_grfmt.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.i"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs/test/test_grfmt.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.s"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs/test/test_grfmt.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.requires:

.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.requires

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.provides: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.requires
	$(MAKE) -f modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build.make modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.provides.build
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.provides

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.provides.build: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o


modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o: ../modules/imgcodecs/test/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o -c /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs/test/test_main.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.i"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs/test/test_main.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.s"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs/test/test_main.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.requires:

.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.requires

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.provides: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.requires
	$(MAKE) -f modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build.make modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.provides.build
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.provides

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.provides.build: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o


# Object files for target opencv_test_imgcodecs
opencv_test_imgcodecs_OBJECTS = \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o"

# External object files for target opencv_test_imgcodecs
opencv_test_imgcodecs_EXTERNAL_OBJECTS =

bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build.make
bin/opencv_test_imgcodecs: lib/libopencv_ts.a
bin/opencv_test_imgcodecs: lib/libopencv_highgui.3.2.0.dylib
bin/opencv_test_imgcodecs: 3rdparty/ippicv/ippicv_osx/lib/libippicv.a
bin/opencv_test_imgcodecs: lib/libopencv_videoio.3.2.0.dylib
bin/opencv_test_imgcodecs: lib/libopencv_imgcodecs.3.2.0.dylib
bin/opencv_test_imgcodecs: lib/libopencv_imgproc.3.2.0.dylib
bin/opencv_test_imgcodecs: lib/libopencv_core.3.2.0.dylib
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/opencv_test_imgcodecs"
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_test_imgcodecs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build: bin/opencv_test_imgcodecs

.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/requires: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.requires
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/requires: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.requires

.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/requires

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/clean:
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs && $(CMAKE_COMMAND) -P CMakeFiles/opencv_test_imgcodecs.dir/cmake_clean.cmake
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/clean

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/depend:
	cd /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0 /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/modules/imgcodecs /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs /Users/tannerorndorff/Documents/Monocleheads/opencv-3.2.0/build/modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/depend

