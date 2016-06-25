#include <cli/CommandFactory.h>

#include <cli/commands/ShowCommand.h>
#include <cli/commands/HelpCommand.h>

namespace LixProc
{
namespace CLI
{

using LixProc::CLI::Commands::Command;
using LixProc::CLI::Commands::HelpCommand;
using LixProc::CLI::Commands::ShowCommand;

std::unique_ptr<Command>
CommandFactory::Make(
    CommandEnum command,
    std::string arguments
)
{
    std::unique_ptr<Command> command_object;

    // Can we reuse commands?
    // After all, they are loaded with fresh arguments each time.
    // We could just call clear() to remove any data from the last run.
    switch ( command )
    {
        case CommandEnum::HELP:
            command_object = std::unique_ptr<Command>(new HelpCommand);
            break;
        case CommandEnum::SHOW:
            command_object = std::unique_ptr<Command>(new ShowCommand);
            break;

    }

    command_object->SetArguments(arguments);

    return command_object;
}

} // End CLI
} // End LixProc
