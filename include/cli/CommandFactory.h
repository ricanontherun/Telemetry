#ifndef CLI_COMMANDS_COMMAND_FACTORY_H
#define CLI_COMMANDS_COMMAND_FACTORY_H

#include <cli/commands/Command.h>

#include <map>
#include <memory>

namespace LixProc
{
namespace CLI
{

using LixProc::CLI::Commands::Command;

class CommandFactory
{
    public:
        enum class CommandEnum {
            HELP,
            SHOW
        };

        static std::map<std::string, CommandEnum> command_map;

        static Command *Make(CommandEnum command,std::string arguments);
        static Command *Make(CommandEnum command);

        static bool IsValidCommand(const std::string &command);
    private:
        static std::map<CommandEnum, std::unique_ptr<Command>> instances;
};

} // End CLI
} // End LixProc

#endif
