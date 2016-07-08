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
#ifndef CORE_UTILS_COMMAND_H
#define CORE_UTILS_COMMAND_H

#include <string>

namespace LixProc
{
namespace Utils
{

struct Command {
    std::string path;
    std::string name;
    std::string arguments;
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
