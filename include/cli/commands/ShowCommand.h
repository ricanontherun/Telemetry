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

        void Run(void);

        enum class ArgumentRegex {
            ALL,
            NAME
        };

        static std::map<std::string, std::string> test;
        static RegexMap<ArgumentRegex> regex_map;
    private:

        void ParseArguments(std::string arguments);
        std::regex GetArgumentRegex(ArgumentRegex name) const;
        bool TestArgumentRegex(ArgumentRegex name) const;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
