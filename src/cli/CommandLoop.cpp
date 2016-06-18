#include <iostream>
#include <string>

#include <cli/CommandLoop.h>

namespace LixProc
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::line_prefix = "lixproc >> ";

CommandLoop::CommandLoop(void)
{

}

void CommandLoop::InitMainLoop(void)
{
    std::string command;

    std::cout << CommandLoop::line_prefix;

    while (std::getline(std::cin, command))
    {
        // Validate Command.

        // Create the command object.

        // Run and print output.

        std::cout << CommandLoop::line_prefix;
    }
}

} // End CLI
} // End SystemMonitor
