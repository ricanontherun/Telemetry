#include <cli/commands/CommandFactory.h>

#include <cli/commands/HelpCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

std::unique_ptr<Command>
CommandFactory::Make(std::string concrete)
{
    std::unique_ptr<Command> command;

    // TODO: Employ an enum and do a switch.
    if ( concrete == "help" )
    {
        command = std::unique_ptr<Command>(new HelpCommand);
    }

    return command;
}

} // End Commands
} // End CLI
} // End LixProc
