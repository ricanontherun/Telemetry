#include <iostream>
#include <cli/commands/HelpCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

void HelpCommand::Run(void)
{
    std::cout << "Hey, this is the Help command!" << std::endl;
}

} // End Commands
} // End CLI
} // End LixProc
