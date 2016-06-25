#include <cli/commands/HelpCommand.h>

#include <iostream>
#include <iomanip>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

void HelpCommand::Run(void)
{
    std::cout << "Available Commands" << std::endl;

    std::cout << std::setw(8) << "help" << std::setw(30) << "Display Help" << std::endl;
    std::cout << std::setw(8) << "show" << std::setw(30) << "Display processes" << std::endl;
}

} // End Commands
} // End CLI
} // End LixProc
