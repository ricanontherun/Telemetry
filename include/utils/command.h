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
#ifndef TELEMETRY_COMMAND_H
#define TELEMETRY_COMMAND_H

#include <string>
#include <cctype>
#include <algorithm>

namespace Telemetry
{
namespace Utils
{

struct Command {
    // Path with trailing forward slash.
    std::string path;

    // Executable name
    std::string name;

    // CLI arguments passed to executable.
    std::string arguments;

    friend std::ostream & operator<<(std::ostream & os, const Command & command) {
        std::string command_string = command.path + command.name + " " + command.arguments;

        // Trim leading whitespace.
        command_string.erase(command_string.begin(), std::find_if(command_string.begin(), command_string.end(), [](char c) {
            return !std::isspace(c);
        }));

        // Trim the trailing whitespace.
        command_string.erase(std::find_if(command_string.rbegin(), command_string.rend(), [](char c) {
            return !std::isspace(c);
        }).base(), command_string.end());

        os << std::move(command_string);

        return os;
    }
};

/**
 * Parse a command string in the form "path/to/executable arguments" into a Command object.
 *
 * Example:
 *  ParseCommandString("/path/to/executable --rf --arg1=yes --arg2=no", command);
 *  ...
 *  command.path = /path/to/
 *  command.name= executable
 *  command.arguments = -rf --arg1=yes --arg2=no
 *
 * @param command_str
 * @param command
 *
 * @return
 */
bool ParseCommandString(std::string command_str, Command &command);

} // End Utils
} // End SysteMonitor

#endif
