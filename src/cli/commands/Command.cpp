#include <iostream>
#include <vector>

#include <cli/commands/Command.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

Command::Command(std::vector<std::string> &arguments)
{
    this->arguments = arguments;
}

} // End Commands
} // End CLI
} // End LixProc
