#include <cli/CommandLoop.h>

#include <string>
#include <iostream>
#include <algorithm>

#include <utils/str.h>
#include <cli/CommandFactory.h>
#include <core/sys/SystemInfo.h>

namespace LixProc
{
namespace CLI
{

// Initialize some constants.
const std::string CommandLoop::welcome = "Welcome to lixproc. Empty line to exit, help to more information.";
const std::string CommandLoop::line_prefix = "lixproc >> ";

void CommandLoop::InitMainLoop(void)
{

    LixProc::SystemInfo::Capture();
    std::string command_str;

    this->ShowWelcome();
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
        CommandFactory::CommandEnum code = CommandFactory::command_map.find(command.name)->second;
        Commands::Command *c = CommandFactory::Make(code, command.arguments);

        // Run and print output.
        c->Run();

        std::cout << CommandLoop::line_prefix;
    }
}


/**
 *--------------------------------------------------
 * Private
 *--------------------------------------------------
 */

void CommandLoop::ParseCommand(
    std::string command_str,
    LixProc::Utils::Command &command
)
{
    LixProc::Utils::ParseCommandString(command_str, command);
}

bool CommandLoop::ValidateCommand(LixProc::Utils::Command &command)
{
    return CommandFactory::IsValidCommand(command.name);
}

void CommandLoop::ShowWelcome() const
{
    std::string ascii_art = "";
        ascii_art += " _    _     ___\n";
        ascii_art += "| |  (_)_ _| _ \\_ _ ___  __\n";
        ascii_art += "| |__| \\ \\ /  _/ '_/ _ \\/ _|\n";
        ascii_art += "|____|_/_\\_\\_| |_| \\___/\\__|\n";

    std::string start = "Type help for usage, empty line to exit.";

    std::cout << ascii_art << std::endl;
    std::cout << start << std::endl << std::endl;
}

} // End CLI
} // End LixProc
