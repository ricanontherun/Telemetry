cmake_minimum_required(VERSION 3.5.1)
project(telemetry)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD 14)

include_directories(
    include
)

set(PROJECT_SOURCE
    src/core/process/Process.cpp
    src/utils/file.cpp
    src/utils/command.cpp
    src/core/sys/SystemInfo.cpp
    src/core/sys/SystemUser.cpp
    src/utils/str.cpp
    src/options.cpp
    src/Collectors/ProcessCollector.cpp
    src/Collectors/DiskCollector.cpp
    src/Collectors/CPUCollector.cpp
    src/utils/shell.cpp
    src/core/sys/cpu.cpp
    src/core/sys/disk.cpp
    src/telemetry.cpp
    src/core/filesystem.cpp
)

add_library(telemetry STATIC ${PROJECT_SOURCE})
