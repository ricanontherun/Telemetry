cmake_minimum_required(VERSION 2.8.9)
project (tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror -Wall")
include_directories(../include)

set(SOURCES
    TestProcess.cpp
    TestSystemUser.cpp
    TestSystemInfo.cpp
    TestCommand.cpp
    TestRegexMap.cpp
    TestProcessManager.cpp

    ../src/core/process/Process.cpp
    ../src/utils/file.cpp
    ../src/utils/command.cpp
    ../src/core/sys/SystemInfo.cpp
    ../src/core/sys/SystemUser.cpp
    ../src/utils/str.cpp
    ../src/options.cpp
    ../src/Collectors/ProcessCollector.cpp
    ../src/Collectors/DiskCollector.cpp
    ../src/Collectors/CPUCollector.cpp
    ../src/utils/shell.cpp
    ../src/core/sys/cpu.cpp
    ../src/core/sys/disk.cpp
    ../src/telemetry.cpp
    ../src/core/filesystem.cpp
)

add_executable(tests ${SOURCES})
