# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build

# Include any dependencies generated for this target.
include tools/CMakeFiles/dictbuilder.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/dictbuilder.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/dictbuilder.dir/flags.make

tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o: tools/CMakeFiles/dictbuilder.dir/flags.make
tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o: ../tools/pinyinime_dictbuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o"
	cd /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o -c /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/tools/pinyinime_dictbuilder.cpp

tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.i"
	cd /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/tools/pinyinime_dictbuilder.cpp > CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.i

tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.s"
	cd /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/tools/pinyinime_dictbuilder.cpp -o CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.s

tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.requires:

.PHONY : tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.requires

tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.provides: tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.requires
	$(MAKE) -f tools/CMakeFiles/dictbuilder.dir/build.make tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.provides.build
.PHONY : tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.provides

tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.provides.build: tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o


# Object files for target dictbuilder
dictbuilder_OBJECTS = \
"CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o"

# External object files for target dictbuilder
dictbuilder_EXTERNAL_OBJECTS =

tools/dictbuilder: tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o
tools/dictbuilder: tools/CMakeFiles/dictbuilder.dir/build.make
tools/dictbuilder: src/libgooglepinyin.so.0.1.0
tools/dictbuilder: tools/CMakeFiles/dictbuilder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dictbuilder"
	cd /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dictbuilder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/dictbuilder.dir/build: tools/dictbuilder

.PHONY : tools/CMakeFiles/dictbuilder.dir/build

tools/CMakeFiles/dictbuilder.dir/requires: tools/CMakeFiles/dictbuilder.dir/pinyinime_dictbuilder.cpp.o.requires

.PHONY : tools/CMakeFiles/dictbuilder.dir/requires

tools/CMakeFiles/dictbuilder.dir/clean:
	cd /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools && $(CMAKE_COMMAND) -P CMakeFiles/dictbuilder.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/dictbuilder.dir/clean

tools/CMakeFiles/dictbuilder.dir/depend:
	cd /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2 /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/tools /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/tools/CMakeFiles/dictbuilder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/dictbuilder.dir/depend
