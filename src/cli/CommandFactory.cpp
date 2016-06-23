#include <cli/CommandFactory.h>

#include <cli/commands/HelpCommand.h>

namespace LixProc
{
namespace CLI
{

using LixProc::CLI::Commands::Command;
using LixProc::CLI::Commands::HelpCommand;

std::unique_ptr<Command>
CommandFactory::Make(CommandEnum com)
{
    std::unique_ptr<Command> command;

    // TODO: Employ an enum and do a switch.
    switch ( com )
    {
        case CommandEnum::HELP:
            command = std::unique_ptr<Command>(new HelpCommand);
            break;

    }

    return command;
}

} // End CLI
} // End LixProc
