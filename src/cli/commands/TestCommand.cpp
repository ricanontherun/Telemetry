#include <iostream>
#include <cli/commands/TestCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

TestCommand::TestCommand(void)
{

}

TestCommand::TestCommand(std::vector<std::string> &arguments) : Command(arguments)
{
}

void TestCommand::Run(void)
{

}

} // End Commands
} // End CLI
} // End LixProc

