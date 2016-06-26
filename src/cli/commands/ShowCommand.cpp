#include <cli/commands/ShowCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

ShowCommand::ShowCommand()
{
}

void ShowCommand::Run(void)
{
    this->ParseArguments(this->arguments);

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::ParseArguments(std::string arguments)
{
}

} // End Commands
} // End CLI
} // End LixProc
