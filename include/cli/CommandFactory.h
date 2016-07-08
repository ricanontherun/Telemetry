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
#ifndef CLI_COMMAND_FACTORY_H
#define CLI_COMMAND_FACTORY_H

#include <cli/commands/Command.h>

#include <map>
#include <memory>

namespace LixProc
{
namespace CLI
{

using LixProc::CLI::Commands::Command;

class CommandFactory
{
    public:
        enum class CommandEnum {
            HELP,
            SHOW
        };

        static std::map<std::string, CommandEnum> command_map;

        static Command *Make(CommandEnum command, std::string arguments);
        static Command *Make(CommandEnum command);

        static bool IsValidCommand(const std::string &command);
        static CommandEnum GetCode(const std::string &command);
    private:
        static std::map<CommandEnum, std::unique_ptr<Command>> instances;
};

} // End CLI
} // End LixProc

#endif
