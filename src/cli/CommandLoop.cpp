#include <cli/CommandLoop.h>

#include <iostream>
#include <string>
#include <algorithm>

#include <cli/CommandFactory.h>

namespace LixProc
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::welcome = "Welcome. Empty line to exit.";
const std::string CommandLoop::line_prefix = "lixproc >> ";

std::map<std::string, CommandFactory::CommandEnum>
CommandLoop::command_map = {
    {"help", CommandFactory::CommandEnum::HELP}
};

void CommandLoop::InitMainLoop(void)
{
    std::string command_str;

    std::cout << CommandLoop::welcome << std::endl;
    std::cout << CommandLoop::line_prefix;

    LixProc::Utils::Command command;

    while (std::getline(std::cin, command_str) && command_str.length() != 0)
    {
        // Parse command
        this->ParseCommand(command_str, command);

        // Validate Command.
        if ( !this->ValidateCommand(command) )
        {
            std::cout << command.name << " is not a valid command. Try help..." << std::endl;
            std::cout << CommandLoop::line_prefix;
            continue;
        }

        // Create the command object.
        CommandFactory::CommandEnum code = CommandLoop::command_map.find(command.name)->second;
        std::unique_ptr<Commands::Command> c = CommandFactory::Make(code);

        // Run and print output.
        c->Run();

        std::cout << CommandLoop::line_prefix;
    }
}

void CommandLoop::ParseCommand(
    std::string command_str,
    LixProc::Utils::Command &command
)
{
    LixProc::Utils::ParseCommandString(command_str, command);
}

bool CommandLoop::ValidateCommand(LixProc::Utils::Command &command)
{
    return command_map.count(command.name) != 0;
}

} // End CLI
} // End LixProc
