# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/supsun/Documents/Magic_fight

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/supsun/Documents/Magic_fight/_build

# Include any dependencies generated for this target.
include CMakeFiles/server_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_app.dir/flags.make

CMakeFiles/server_app.dir/sources/actions.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/sources/actions.cpp.o: ../sources/actions.cpp
CMakeFiles/server_app.dir/sources/actions.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_app.dir/sources/actions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/sources/actions.cpp.o -MF CMakeFiles/server_app.dir/sources/actions.cpp.o.d -o CMakeFiles/server_app.dir/sources/actions.cpp.o -c /home/supsun/Documents/Magic_fight/sources/actions.cpp

CMakeFiles/server_app.dir/sources/actions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/sources/actions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/sources/actions.cpp > CMakeFiles/server_app.dir/sources/actions.cpp.i

CMakeFiles/server_app.dir/sources/actions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/sources/actions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/sources/actions.cpp -o CMakeFiles/server_app.dir/sources/actions.cpp.s

CMakeFiles/server_app.dir/sources/board.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/sources/board.cpp.o: ../sources/board.cpp
CMakeFiles/server_app.dir/sources/board.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server_app.dir/sources/board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/sources/board.cpp.o -MF CMakeFiles/server_app.dir/sources/board.cpp.o.d -o CMakeFiles/server_app.dir/sources/board.cpp.o -c /home/supsun/Documents/Magic_fight/sources/board.cpp

CMakeFiles/server_app.dir/sources/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/sources/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/sources/board.cpp > CMakeFiles/server_app.dir/sources/board.cpp.i

CMakeFiles/server_app.dir/sources/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/sources/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/sources/board.cpp -o CMakeFiles/server_app.dir/sources/board.cpp.s

CMakeFiles/server_app.dir/sources/EventQueue.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/sources/EventQueue.cpp.o: ../sources/EventQueue.cpp
CMakeFiles/server_app.dir/sources/EventQueue.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server_app.dir/sources/EventQueue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/sources/EventQueue.cpp.o -MF CMakeFiles/server_app.dir/sources/EventQueue.cpp.o.d -o CMakeFiles/server_app.dir/sources/EventQueue.cpp.o -c /home/supsun/Documents/Magic_fight/sources/EventQueue.cpp

CMakeFiles/server_app.dir/sources/EventQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/sources/EventQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/sources/EventQueue.cpp > CMakeFiles/server_app.dir/sources/EventQueue.cpp.i

CMakeFiles/server_app.dir/sources/EventQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/sources/EventQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/sources/EventQueue.cpp -o CMakeFiles/server_app.dir/sources/EventQueue.cpp.s

CMakeFiles/server_app.dir/sources/object.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/sources/object.cpp.o: ../sources/object.cpp
CMakeFiles/server_app.dir/sources/object.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server_app.dir/sources/object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/sources/object.cpp.o -MF CMakeFiles/server_app.dir/sources/object.cpp.o.d -o CMakeFiles/server_app.dir/sources/object.cpp.o -c /home/supsun/Documents/Magic_fight/sources/object.cpp

CMakeFiles/server_app.dir/sources/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/sources/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/sources/object.cpp > CMakeFiles/server_app.dir/sources/object.cpp.i

CMakeFiles/server_app.dir/sources/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/sources/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/sources/object.cpp -o CMakeFiles/server_app.dir/sources/object.cpp.s

CMakeFiles/server_app.dir/sources/projectiles.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/sources/projectiles.cpp.o: ../sources/projectiles.cpp
CMakeFiles/server_app.dir/sources/projectiles.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server_app.dir/sources/projectiles.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/sources/projectiles.cpp.o -MF CMakeFiles/server_app.dir/sources/projectiles.cpp.o.d -o CMakeFiles/server_app.dir/sources/projectiles.cpp.o -c /home/supsun/Documents/Magic_fight/sources/projectiles.cpp

CMakeFiles/server_app.dir/sources/projectiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/sources/projectiles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/sources/projectiles.cpp > CMakeFiles/server_app.dir/sources/projectiles.cpp.i

CMakeFiles/server_app.dir/sources/projectiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/sources/projectiles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/sources/projectiles.cpp -o CMakeFiles/server_app.dir/sources/projectiles.cpp.s

CMakeFiles/server_app.dir/sources/action_classes.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/sources/action_classes.cpp.o: ../sources/action_classes.cpp
CMakeFiles/server_app.dir/sources/action_classes.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server_app.dir/sources/action_classes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/sources/action_classes.cpp.o -MF CMakeFiles/server_app.dir/sources/action_classes.cpp.o.d -o CMakeFiles/server_app.dir/sources/action_classes.cpp.o -c /home/supsun/Documents/Magic_fight/sources/action_classes.cpp

CMakeFiles/server_app.dir/sources/action_classes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/sources/action_classes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/sources/action_classes.cpp > CMakeFiles/server_app.dir/sources/action_classes.cpp.i

CMakeFiles/server_app.dir/sources/action_classes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/sources/action_classes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/sources/action_classes.cpp -o CMakeFiles/server_app.dir/sources/action_classes.cpp.s

CMakeFiles/server_app.dir/include/NetCommon.cpp.o: CMakeFiles/server_app.dir/flags.make
CMakeFiles/server_app.dir/include/NetCommon.cpp.o: ../include/NetCommon.cpp
CMakeFiles/server_app.dir/include/NetCommon.cpp.o: CMakeFiles/server_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server_app.dir/include/NetCommon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_app.dir/include/NetCommon.cpp.o -MF CMakeFiles/server_app.dir/include/NetCommon.cpp.o.d -o CMakeFiles/server_app.dir/include/NetCommon.cpp.o -c /home/supsun/Documents/Magic_fight/include/NetCommon.cpp

CMakeFiles/server_app.dir/include/NetCommon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_app.dir/include/NetCommon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/supsun/Documents/Magic_fight/include/NetCommon.cpp > CMakeFiles/server_app.dir/include/NetCommon.cpp.i

CMakeFiles/server_app.dir/include/NetCommon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_app.dir/include/NetCommon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/supsun/Documents/Magic_fight/include/NetCommon.cpp -o CMakeFiles/server_app.dir/include/NetCommon.cpp.s

# Object files for target server_app
server_app_OBJECTS = \
"CMakeFiles/server_app.dir/sources/actions.cpp.o" \
"CMakeFiles/server_app.dir/sources/board.cpp.o" \
"CMakeFiles/server_app.dir/sources/EventQueue.cpp.o" \
"CMakeFiles/server_app.dir/sources/object.cpp.o" \
"CMakeFiles/server_app.dir/sources/projectiles.cpp.o" \
"CMakeFiles/server_app.dir/sources/action_classes.cpp.o" \
"CMakeFiles/server_app.dir/include/NetCommon.cpp.o"

# External object files for target server_app
server_app_EXTERNAL_OBJECTS =

libserver_app.a: CMakeFiles/server_app.dir/sources/actions.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/sources/board.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/sources/EventQueue.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/sources/object.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/sources/projectiles.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/sources/action_classes.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/include/NetCommon.cpp.o
libserver_app.a: CMakeFiles/server_app.dir/build.make
libserver_app.a: CMakeFiles/server_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/supsun/Documents/Magic_fight/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libserver_app.a"
	$(CMAKE_COMMAND) -P CMakeFiles/server_app.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_app.dir/build: libserver_app.a
.PHONY : CMakeFiles/server_app.dir/build

CMakeFiles/server_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_app.dir/clean

CMakeFiles/server_app.dir/depend:
	cd /home/supsun/Documents/Magic_fight/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/supsun/Documents/Magic_fight /home/supsun/Documents/Magic_fight /home/supsun/Documents/Magic_fight/_build /home/supsun/Documents/Magic_fight/_build /home/supsun/Documents/Magic_fight/_build/CMakeFiles/server_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_app.dir/depend

