#include <iostream>
#include <unistd.h>
#include "test_header.h"

#include <core/process/Process.h>
#include <utils/command.h>

using SystemMonitor::Core::Process;
using SystemMonitor::Utils::ExtractCommandElements;

TEST_CASE("SystemMonitor::Core::Utils::ExtractCommandElements()")
{
    SECTION("It can parse an empty string")
    {
        std::string command_string = "";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.empty());
        REQUIRE(command.executable.empty());
        REQUIRE(command.arguments.empty());
    }

    SECTION("It can parse just an executable")
    {
        std::string command_string = "executable";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.empty());
        REQUIRE(command.executable == command_string);
        REQUIRE(command.arguments.empty());
    }

    SECTION("It can parse a path and an executable")
    {
        std::string command_string = "/path/to/executable";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path =="/path/to/");
        REQUIRE(command.executable == "executable");
        REQUIRE(command.arguments.empty());
    }

    SECTION("It can parse a path, an executable and arguments")
    {
        std::string command_string = "/path/to/executable -rf --argument1=value1";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path == "/path/to/");
        REQUIRE(command.executable == "executable");
        REQUIRE(command.arguments == "-rf --argument1=value1");
    }

    SECTION("It can parse an executable and arguments")
    {
        std::string command_string = "executable -rf --argument1=value1";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.empty());
        REQUIRE(command.executable == "executable");
        REQUIRE(command.arguments == "-rf --argument1=value1");
    }
}
