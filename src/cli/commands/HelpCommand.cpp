#include <cli/commands/HelpCommand.h>

#include <iomanip>
#include <iostream>

#include <cli/CommandFactory.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

HelpCommand::HelpCommand(){

}

void HelpCommand::Run(void)
{
    if ( this->arguments.length() == 0 || !CommandFactory::IsValidCommand(this->arguments) ) {
        this->ShowGeneralHelp();
    } else {
    }
}

/**
 *--------------------------------------------------
 * Private
 *--------------------------------------------------
 */
void HelpCommand::ShowGeneralHelp() const
{
    std::cout << "Available Commands" << std::endl;

    std::cout << std::setw(8) << "help" << std::setw(30) << "Display Help" << std::endl;
    std::cout << std::setw(8) << "show" << std::setw(30) << "Display processes" << std::endl;
}

} // End Commands
} // End CLI
} // End LixProc
