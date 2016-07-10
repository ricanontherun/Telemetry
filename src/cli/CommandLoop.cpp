// Copyright (C) 2016 Christian Roman
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <cli/CommandLoop.h>

#include <string>
#include <iostream>
#include <algorithm>

#include <utils/str.h>
#include <cli/CommandFactory.h>
#include <core/sys/SystemInfo.h>

namespace LixProc
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::welcome = "Welcome to lixproc. Empty line to exit, help to more information.";
const std::string CommandLoop::line_prefix = "lixproc >> ";

void CommandLoop::Init(void)
{

    LixProc::SystemInfo::Capture();
    std::string command_str;

    CommandLoop::ShowWelcome();
    std::cout << CommandLoop::line_prefix;

    LixProc::Utils::Command command;

    while (std::getline(std::cin, command_str) && command_str.length() != 0)
    {
        // Parse command
        CommandLoop::ParseCommand(command_str, command);

        // Validate Command.
        if ( !CommandLoop::ValidateCommand(command) )
        {
            std::cout << command.name << " is not a valid command. Try help..." << std::endl;
            std::cout << CommandLoop::line_prefix;
            continue;
        }

        Commands::Command *c = CommandFactory::Make(
            CommandFactory::GetCode(command.name),
            command.arguments
        );

        // Run and print output.
        c->Run();

        std::cout << CommandLoop::line_prefix;
    }
}


/**
 *--------------------------------------------------
 * Private
 *--------------------------------------------------
 */

void CommandLoop::ParseCommand(
    std::string command_str,
    LixProc::Utils::Command &command
)
{
    LixProc::Utils::ParseCommandString(command_str, command);
}

bool CommandLoop::ValidateCommand(LixProc::Utils::Command &command)
{
    return CommandFactory::IsValidCommand(command.name);
}

void CommandLoop::ShowWelcome()
{
    std::string ascii_art = "";
        ascii_art += " _    _     ___\n";
        ascii_art += "| |  (_)_ _| _ \\_ _ ___  __\n";
        ascii_art += "| |__| \\ \\ /  _/ '_/ _ \\/ _|\n";
        ascii_art += "|____|_/_\\_\\_| |_| \\___/\\__|\n";

    std::string start = "Type help [COMMAND] for usage, empty line to exit.";

    std::cout << ascii_art << "\n";
    std::cout << start << "\n" << "\n";
}

} // End CLI
} // End LixProc
