#include <cli/commands/ShowCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

std::map<ShowCommand::ArgumentRegex, std::regex>
ShowCommand::argument_regex_map = {
    {ShowCommand::ArgumentRegex::ALL, std::regex("^all$")},
    {ShowCommand::ArgumentRegex::NAME, std::regex("^name:[[:w:]]+$")}
};

void ShowCommand::Run(void) {
    std::cout << "Running the show command" << std::endl;
}

} // End Commands
} // End CLI
} // End LixProc
