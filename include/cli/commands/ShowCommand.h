#ifndef CLI_COMMANDS_SHOW_COMMAND_H
#define CLI_COMMANDS_SHOW_COMMAND_H

#include <cli/commands/Command.h>

#include <iostream>

#include <utils/RegexMap.h>
#include <map>

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
        void ParseArguments(std::string arguments);
};

} // End Commands
} // End CLI
} // End LixProc

#endif
