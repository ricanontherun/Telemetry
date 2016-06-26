#include <iostream>
#include <vector>

#include <cli/commands/Command.h>

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
