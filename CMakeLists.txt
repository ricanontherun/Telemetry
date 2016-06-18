cmake_minimum_required(VERSION 2.8.9)
project(linux_process_monitor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Werror -Wall")
include_directories(include)

set(SOURCES
    src/main.cpp
    src/manager/ProcessManager.cpp
    src/core/process/Process.cpp
    src/utils/file.cpp
    src/utils/command.cpp
    src/utils/str.cpp
    src/core/sys/SystemInfo.cpp
    src/core/sys/SystemUser.cpp
    src/cli/CommandLoop.cpp
    )

add_executable(lixproc ${SOURCES})
