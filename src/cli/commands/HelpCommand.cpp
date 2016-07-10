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
#include <cli/commands/HelpCommand.h>

#include <iomanip>
#include <iostream>

#include <cli/CommandFactory.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

HelpCommand::HelpCommand(){

}

void HelpCommand::Run()
{
    if ( this->arguments.length() == 0 ) {
        this->PrintHelp();
    } else {
        if ( CommandFactory::IsValidCommand(this->arguments) == false ) {
            std::cout << "That command doesn't exist" << std::endl;
        } else {
            Command *command = CommandFactory::Make(CommandFactory::GetCode(this->arguments));
            command->PrintHelp();
        }
    }
}

void HelpCommand::PrintHelp() const
{
    int command_width = 10;
    std::cout << std::setw(command_width) << std::left << "Command" << "Description" << std::endl << std::endl;
    std::cout << std::setw(command_width) << "help" << "Display Help" << std::endl;
    std::cout << std::setw(command_width) << "show" << "List Processes" << std::endl;
}

} // End Commands
} // End CLI
} // End LixProc
