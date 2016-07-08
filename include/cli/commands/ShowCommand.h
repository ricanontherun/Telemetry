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
#ifndef CLI_COMMANDS_SHOW_COMMAND_H
#define CLI_COMMANDS_SHOW_COMMAND_H

#include <cli/commands/Command.h>

#include <map>
#include <memory>
#include <iostream>

#include <utils/RegexMap.h>
#include <manager/ProcessManager.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

using LixProc::Manager::ProcessManager;
using LixProc::Manager::ProcessIterators;

class ShowCommand : public Command
{
    public:
        ShowCommand(void);
        ~ShowCommand(void);

        void Run(void);
        RegexMap<std::string> regex_map;
    private:
        void Show() const;
        void Show(const std::string &name) const;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
