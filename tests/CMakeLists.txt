cmake_minimum_required(VERSION 2.8.9)
project (tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Werror -Wall")
include_directories(../include)

set(SOURCES
    TestUtils.cpp
    TestProcess.cpp
    TestSystemUser.cpp
    TestSystemInfo.cpp
    TestCommand.cpp
    TestRegexMap.cpp
    ../src/core/process/Process.cpp
    ../src/utils/file.cpp
    ../src/core/sys/SystemInfo.cpp
    ../src/core/sys/SystemUser.cpp
    ../src/utils/command.cpp
    ../src/utils/str.cpp)

add_executable(tests ${SOURCES})
