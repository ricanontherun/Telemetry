#include <iostream>
#include <string>

#include <cli/CommandLoop.h>

namespace SystemMonitor
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::welcome = "Welcome. Empty line to exit.";
const std::string CommandLoop::line_prefix = "lixproc >> ";

void CommandLoop::InitMainLoop(void)
{
    std::string command_str;

    std::cout << CommandLoop::welcome << std::endl;
    std::cout << CommandLoop::line_prefix;

    SystemMonitor::Utils::Command command;

    while (std::getline(std::cin, command_str) && command_str.length() != 0)
    {
        // Parse command
        this->ParseCommand(command_str, command);

        // Validate Command.

        // Create the command object.

        // Run and print output.

        std::cout << CommandLoop::line_prefix;
    }
}

void CommandLoop::ParseCommand(std::string command_str, SystemMonitor::Utils::Command &command)
{
    SystemMonitor::Utils::ParseCommandString(command_str, command);
}

LixProc::CLI::Commands::Command *CommandLoop::Instance(std::string command)
{
    return NULL;
}

} // End CLI
} // End SystemMonitor
