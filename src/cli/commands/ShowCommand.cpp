#include <cli/commands/ShowCommand.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

ShowCommand::ShowCommand()
{
    this->regex_map
        .Set("all", "^all$")
        .Set("name", "^name:[[:w:]]+$");
}

void ShowCommand::Run(void)
{
    this->ParseArguments(this->arguments);

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::ParseArguments(std::string arguments)
{
    if ( this->regex_map.Test("all", arguments) ) {
        std::cout << "You gave the all option" << std::endl;
    } else if ( this->regex_map.Test("name", arguments) ) {
        std::cout << "You gave the name: option" << std::endl;
    } else {
        std::cout << "Unknown option...try help" << std::endl;
    }
}

} // End Commands
} // End CLI
} // End LixProc
