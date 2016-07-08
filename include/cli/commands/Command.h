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
#ifndef CLI_COMMANDS_COMMAND_H
#define CLI_COMMANDS_COMMAND_H

#include <string>
#include <vector>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class Command
{
    public:
        Command(void) {};
        virtual ~Command() {};

        virtual void Run(void) = 0;
        void SetArguments(std::string arguments);
    protected:
        std::string arguments;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
