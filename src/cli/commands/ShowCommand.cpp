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
#include <cli/commands/ShowCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

ShowCommand::ShowCommand()
{
    this->regex_map
        .Set("all", "^all$")
        .Set("name", "^name:[[:w:]]+$");
}

ShowCommand::~ShowCommand()
{
}

void ShowCommand::Run(void)
{
    if ( this->regex_map.Test("all", this->arguments) ) {
        this->Show();
    } else if ( this->regex_map.Test("name", this->arguments) ) {
        std::size_t found = this->arguments.find_first_of(":");
        std::string name = this->arguments.erase(0, found + 1);

        this->Show(name);
    } else {
        std::cout << "Unknown option...try help" << std::endl;
    }

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::Show() const
{
    ProcessIterators iterators = ProcessManager::Load();

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}

void ShowCommand::Show(const std::string &name) const
{
    ProcessIterators iterators = ProcessManager::Load(name);

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}

} // End Commands
} // End CLI
} // End LixProc
