#include <cli/commands/Command.h>

#include <vector>
#include <iostream>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

void Command::SetArguments(std::string arguments)
{
    this->arguments = arguments;
}


} // End Commands
} // End CLI
} // End LixProc
