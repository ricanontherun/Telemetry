# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_SOURCE_DIR = /home/croman/projects/system_monitor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/croman/projects/system_monitor

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/croman/projects/system_monitor/CMakeFiles /home/croman/projects/system_monitor/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/croman/projects/system_monitor/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named sysmon

# Build rule for target.
sysmon: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sysmon
.PHONY : sysmon

# fast build rule for target.
sysmon/fast:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/build
.PHONY : sysmon/fast

core/process/Process.o: core/process/Process.cpp.o
.PHONY : core/process/Process.o

# target to build an object file
core/process/Process.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/process/Process.cpp.o
.PHONY : core/process/Process.cpp.o

core/process/Process.i: core/process/Process.cpp.i
.PHONY : core/process/Process.i

# target to preprocess a source file
core/process/Process.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/process/Process.cpp.i
.PHONY : core/process/Process.cpp.i

core/process/Process.s: core/process/Process.cpp.s
.PHONY : core/process/Process.s

# target to generate assembly for a file
core/process/Process.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/process/Process.cpp.s
.PHONY : core/process/Process.cpp.s

core/sys/SystemInfo.o: core/sys/SystemInfo.cpp.o
.PHONY : core/sys/SystemInfo.o

# target to build an object file
core/sys/SystemInfo.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/sys/SystemInfo.cpp.o
.PHONY : core/sys/SystemInfo.cpp.o

core/sys/SystemInfo.i: core/sys/SystemInfo.cpp.i
.PHONY : core/sys/SystemInfo.i

# target to preprocess a source file
core/sys/SystemInfo.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/sys/SystemInfo.cpp.i
.PHONY : core/sys/SystemInfo.cpp.i

core/sys/SystemInfo.s: core/sys/SystemInfo.cpp.s
.PHONY : core/sys/SystemInfo.s

# target to generate assembly for a file
core/sys/SystemInfo.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/sys/SystemInfo.cpp.s
.PHONY : core/sys/SystemInfo.cpp.s

core/sys/SystemUser.o: core/sys/SystemUser.cpp.o
.PHONY : core/sys/SystemUser.o

# target to build an object file
core/sys/SystemUser.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/sys/SystemUser.cpp.o
.PHONY : core/sys/SystemUser.cpp.o

core/sys/SystemUser.i: core/sys/SystemUser.cpp.i
.PHONY : core/sys/SystemUser.i

# target to preprocess a source file
core/sys/SystemUser.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/sys/SystemUser.cpp.i
.PHONY : core/sys/SystemUser.cpp.i

core/sys/SystemUser.s: core/sys/SystemUser.cpp.s
.PHONY : core/sys/SystemUser.s

# target to generate assembly for a file
core/sys/SystemUser.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/sys/SystemUser.cpp.s
.PHONY : core/sys/SystemUser.cpp.s

core/util/file.o: core/util/file.cpp.o
.PHONY : core/util/file.o

# target to build an object file
core/util/file.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/util/file.cpp.o
.PHONY : core/util/file.cpp.o

core/util/file.i: core/util/file.cpp.i
.PHONY : core/util/file.i

# target to preprocess a source file
core/util/file.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/util/file.cpp.i
.PHONY : core/util/file.cpp.i

core/util/file.s: core/util/file.cpp.s
.PHONY : core/util/file.s

# target to generate assembly for a file
core/util/file.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/util/file.cpp.s
.PHONY : core/util/file.cpp.s

core/util/str.o: core/util/str.cpp.o
.PHONY : core/util/str.o

# target to build an object file
core/util/str.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/util/str.cpp.o
.PHONY : core/util/str.cpp.o

core/util/str.i: core/util/str.cpp.i
.PHONY : core/util/str.i

# target to preprocess a source file
core/util/str.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/util/str.cpp.i
.PHONY : core/util/str.cpp.i

core/util/str.s: core/util/str.cpp.s
.PHONY : core/util/str.s

# target to generate assembly for a file
core/util/str.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/core/util/str.cpp.s
.PHONY : core/util/str.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/main.cpp.s
.PHONY : main.cpp.s

manager/ProcessManager.o: manager/ProcessManager.cpp.o
.PHONY : manager/ProcessManager.o

# target to build an object file
manager/ProcessManager.cpp.o:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/manager/ProcessManager.cpp.o
.PHONY : manager/ProcessManager.cpp.o

manager/ProcessManager.i: manager/ProcessManager.cpp.i
.PHONY : manager/ProcessManager.i

# target to preprocess a source file
manager/ProcessManager.cpp.i:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/manager/ProcessManager.cpp.i
.PHONY : manager/ProcessManager.cpp.i

manager/ProcessManager.s: manager/ProcessManager.cpp.s
.PHONY : manager/ProcessManager.s

# target to generate assembly for a file
manager/ProcessManager.cpp.s:
	$(MAKE) -f CMakeFiles/sysmon.dir/build.make CMakeFiles/sysmon.dir/manager/ProcessManager.cpp.s
.PHONY : manager/ProcessManager.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... sysmon"
	@echo "... core/process/Process.o"
	@echo "... core/process/Process.i"
	@echo "... core/process/Process.s"
	@echo "... core/sys/SystemInfo.o"
	@echo "... core/sys/SystemInfo.i"
	@echo "... core/sys/SystemInfo.s"
	@echo "... core/sys/SystemUser.o"
	@echo "... core/sys/SystemUser.i"
	@echo "... core/sys/SystemUser.s"
	@echo "... core/util/file.o"
	@echo "... core/util/file.i"
	@echo "... core/util/file.s"
	@echo "... core/util/str.o"
	@echo "... core/util/str.i"
	@echo "... core/util/str.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... manager/ProcessManager.o"
	@echo "... manager/ProcessManager.i"
	@echo "... manager/ProcessManager.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

