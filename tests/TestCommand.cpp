#include <iostream>
#include <unistd.h>
#include "test_header.h"

#include "../core/process/Process.h"
#include "../core/util/command.h"

using SystemMonitor::Core::Process;
using SystemMonitor::Utils::ExtractCommandElements;

TEST_CASE("SystemMonitor::Core::Utils::ExtractCommandElements()")
{
    SECTION("It can parse an empty string")
    {
        std::string command_string = "";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.length() == 0);
        REQUIRE(command.executable.length() == 0);
        REQUIRE(command.arguments.length() == 0);
    }

    SECTION("It can parse just an executable")
    {
        std::string command_string = "executable";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.length() == 0);
        REQUIRE(command.executable.length() == command_string.length());
        REQUIRE(command.arguments.length() == 0);
    }

    SECTION("It can parse a path and an executable")
    {
        std::string command_string = "/path/to/executable";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.compare("/path/to/") == 0);
        REQUIRE(command.executable.compare("executable") == 0);
        REQUIRE(command.arguments.length() == 0);
    }

    SECTION("It can parse a path, an executable and arguments")
    {
        std::string command_string = "/path/to/executable -rf --argument1=value1";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.compare("/path/to/") == 0);
        REQUIRE(command.executable.compare("executable") == 0);
        REQUIRE(command.arguments.compare("-rf --argument1=value1") == 0);
    }

    SECTION("It can parse an executable and arguments")
    {
        std::string command_string = "executable -rf --argument1=value1";
        Process::Command command;

        ExtractCommandElements(command_string, command);

        REQUIRE(command.path.length() == 0);
        REQUIRE(command.executable.compare("executable") == 0);
        REQUIRE(command.arguments.compare("-rf --argument1=value1") == 0);
    }
}
