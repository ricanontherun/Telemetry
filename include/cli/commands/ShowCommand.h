#ifndef CLI_COMMANDS_SHOW_COMMAND_H
#define CLI_COMMANDS_SHOW_COMMAND_H

#include <cli/commands/Command.h>

#include <map>
#include <regex>
#include <iostream>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class ShowCommand : public Command
{
    public:
        ShowCommand(void) {};
        void Run(void);
    private:
        enum class ArgumentRegex {
            ALL,
            NAME
        };

        static std::map<ArgumentRegex, std::regex> argument_regex_map;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
