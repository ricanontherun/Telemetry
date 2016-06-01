cmake_minimum_required(VERSION 2.8.9)
project(sysmon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Werror")

# These backwards paths are a code-smell...
set(SOURCES
    main.cpp
    manager/ProcessManager.cpp
    core/process/Process.cpp
    core/util/file.cpp
    core/sys/SystemInfo.cpp
    core/sys/SystemUser.cpp
    core/util/str.cpp)

add_executable(sysmon ${SOURCES})
