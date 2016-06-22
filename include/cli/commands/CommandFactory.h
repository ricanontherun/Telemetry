#ifndef CLI_COMMANDS_COMMAND_FACTORY_H
#define CLI_COMMANDS_COMMAND_FACTORY_H

#include <cli/commands/Command.h>

#include <memory>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

using LixProc::CLI::Commands::Command;

class CommandFactory
{
    public:
        static std::unique_ptr<Command> Make(std::string concrete);
};

} // End Commands
} // End CLI
} // End LixProc

#endif
