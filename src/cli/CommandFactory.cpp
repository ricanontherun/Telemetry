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

std::map<std::string, CommandFactory::CommandEnum>
CommandFactory::command_map = {
    {"help", CommandFactory::CommandEnum::HELP},
    {"show", CommandFactory::CommandEnum::SHOW}
};

std::map<
    CommandFactory::CommandEnum,
    std::unique_ptr<Command>>
CommandFactory::instances;

Command *CommandFactory::Make(
    CommandEnum command,
    std::string arguments
)
{
    Command *command_object = CommandFactory::Make(command);
    command_object->SetArguments(arguments);

    return command_object;
}

Command *CommandFactory::Make(CommandEnum command)
{
    auto it = CommandFactory::instances.find(command);

    if ( it != CommandFactory::instances.end() )
    {
        return it->second.get();
    }

    std::unique_ptr<Command> command_object;

    switch ( command )
    {
        case CommandEnum::HELP:
            command_object = std::unique_ptr<Command>(new HelpCommand);
            break;
        case CommandEnum::SHOW:
            command_object = std::unique_ptr<Command>(new ShowCommand);
            break;
    }

    CommandFactory::instances[command] = std::move(command_object);

    return CommandFactory::instances[command].get();
}

bool CommandFactory::IsValidCommand(const std::string &command)
{
    return CommandFactory::command_map.find(command) != CommandFactory::command_map.end();
}

} // End CLI
} // End LixProc
