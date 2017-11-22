#include <iostream>
#include <unistd.h>
#include "test_header.h"

#include <utils/command.h>

using Telemetry::Utils::ParseCommandString;
using Telemetry::Utils::Command;

TEST_CASE("Telemetry::Core::Utils::ParseCommandString()")
{
    SECTION("It can parse an empty string")
    {
        std::string command_string = "";
        Command command;

        ParseCommandString(command_string, command);

        REQUIRE(command.path.empty());
        REQUIRE(command.name.empty());
        REQUIRE(command.arguments.empty());
    }

    SECTION("It can parse just an name")
    {
        std::string command_string = "name";
        Command command;

        ParseCommandString(command_string, command);

        REQUIRE(command.path.empty());
        REQUIRE(command.name == command_string);
        REQUIRE(command.arguments.empty());
    }

    SECTION("It can parse a path and an name")
    {
        std::string command_string = "/path/to/name";
        Command command;

        ParseCommandString(command_string, command);

        REQUIRE(command.path =="/path/to/");
        REQUIRE(command.name == "name");
        REQUIRE(command.arguments.empty());
    }

    SECTION("It can parse a path, an name and arguments")
    {
        std::string command_string = "/path/to/name -rf --argument1=value1";
        Command command;

        ParseCommandString(command_string, command);

        REQUIRE(command.path == "/path/to/");
        REQUIRE(command.name == "name");
        REQUIRE(command.arguments == "-rf --argument1=value1");
    }

    SECTION("It can parse an name and arguments")
    {
        std::string command_string = "name -rf --argument1=value1";
        Command command;

        ParseCommandString(command_string, command);

        REQUIRE(command.path.empty());
        REQUIRE(command.name == "name");
        REQUIRE(command.arguments == "-rf --argument1=value1");
    }

    SECTION("It can parse a local script in the form ./exe")
    {
        std::string command_string = "./heck";
        Command command;

        ParseCommandString(command_string, command);

        REQUIRE(command.path == "./");
        REQUIRE(command.name == "heck");
        REQUIRE(command.arguments.empty());
    }
}
