#include <iostream>
#include <string>

#include <cli/CommandLoop.h>

using SystemMonitor::Utils::ParseCommandString;

namespace LixProc
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::welcome = "Welcome. Empty line to exit.";
const std::string CommandLoop::line_prefix = "lixproc >> ";

void CommandLoop::InitMainLoop(void)
{
    std::string command;

    std::cout << CommandLoop::welcome << std::endl;
    std::cout << CommandLoop::line_prefix;

    while (std::getline(std::cin, command) && command.length() != 0)
    {
        // Parse command
        // Validate Command.

        // Create the command object.

        // Run and print output.

        std::cout << CommandLoop::line_prefix;
    }
}

void CommandLoop::ParseCommand(std::string command, SystemMonitor::Utils::Command &command)
{

}

} // End CLI
} // End SystemMonitor
