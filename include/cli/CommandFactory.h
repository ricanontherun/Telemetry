#ifndef CLI_COMMANDS_COMMAND_FACTORY_H
#define CLI_COMMANDS_COMMAND_FACTORY_H

#include <cli/commands/Command.h>

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

        static std::unique_ptr<Command> Make(
            CommandEnum command,
            std::string arguments
        );
};

} // End CLI
} // End LixProc

#endif
