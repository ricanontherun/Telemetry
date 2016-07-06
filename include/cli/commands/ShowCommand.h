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
