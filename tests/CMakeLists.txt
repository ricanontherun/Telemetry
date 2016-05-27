cmake_minimum_required(VERSION 2.8.9)
project (tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# These backwards paths are a code-smell...
set(SOURCES
    utils.cpp
    process.cpp
    SystemUser.cpp
    SystemInfo.cpp
    ../core/process/Process.cpp
    ../core/util/file.cpp
    ../core/sys/SystemInfo.cpp
    ../core/sys/SystemUser.cpp
    ../core/util/str.cpp)

add_executable(tests ${SOURCES})
