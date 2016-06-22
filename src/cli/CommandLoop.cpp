#include <iostream>
#include <string>
#include <algorithm>

#include <cli/CommandLoop.h>

namespace LixProc
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::welcome = "Welcome. Empty line to exit.";
const std::string CommandLoop::line_prefix = "lixproc >> ";

std::vector<std::string> CommandLoop::commands = {
    "help"
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

        // Run and print output.

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
    bool found = std::find(
        this->commands.begin(),
        this->commands.end(),
        command.name
    ) != this->commands.end();

    return found;
}

LixProc::CLI::Commands::Command *CommandLoop::Instance(std::string command)
{
    return NULL;
}

} // End CLI
} // End LixProc
