#ifndef CLI_COMMANDS_SHOW_COMMAND_H
#define CLI_COMMANDS_SHOW_COMMAND_H

#include <cli/commands/Command.h>

#include <map>
#include <memory>
#include <iostream>

#include <utils/RegexMap.h>
#include <core/manager/ProcessManager.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class ShowCommand : public Command
{
    public:
        ShowCommand(void);
        ~ShowCommand(void);

        void Run(void);
        RegexMap<std::string> regex_map;
    private:
        std::unique_ptr<LixProc::Core::Manager::ProcessManager> process_manager;
        void ParseArguments(std::string arguments);
};

} // End Commands
} // End CLI
} // End LixProc

#endif
