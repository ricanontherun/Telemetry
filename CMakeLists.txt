cmake_minimum_required(VERSION 3.5.1)
project(lixproc)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=c++14)

include_directories(include)

set(PROJECT_SOURCE
    src/main.cpp
    src/core/process/Process.cpp
    src/utils/file.cpp
    src/utils/command.cpp
    src/utils/str.cpp
    src/core/sys/SystemInfo.cpp
    src/core/sys/SystemUser.cpp
    src/options.cpp
    src/Collectors/ProcessCollector.cpp)

add_executable(lixproc ${PROJECT_SOURCE})
