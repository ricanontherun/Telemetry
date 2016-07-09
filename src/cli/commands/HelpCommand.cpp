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

void HelpCommand::Run(void)
{
    if ( this->arguments.length() == 0 || !CommandFactory::IsValidCommand(this->arguments) ) {
        this->ShowGeneralHelp();
    } else {
    }
}

/**
 *--------------------------------------------------
 * Private
 *--------------------------------------------------
 */
void HelpCommand::ShowGeneralHelp() const
{
    std::cout << "Available Commands" << std::endl;

    std::cout << std::setw(8) << "help" << std::setw(30) << "Display Help" << std::endl;
    std::cout << std::setw(8) << "show" << std::setw(30) << "Display processes" << std::endl;
}

} // End Commands
} // End CLI
} // End LixProc
