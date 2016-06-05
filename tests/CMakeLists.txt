cmake_minimum_required(VERSION 2.8.9)
project (tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES
    TestUtils.cpp
    TestProcess.cpp
    TestSystemUser.cpp
    TestSystemInfo.cpp
    TestCommand.cpp
    ../core/process/Process.cpp
    ../core/util/file.cpp
    ../core/sys/SystemInfo.cpp
    ../core/sys/SystemUser.cpp
    ../core/util/command.cpp
    ../core/util/str.cpp)

add_executable(tests ${SOURCES})
