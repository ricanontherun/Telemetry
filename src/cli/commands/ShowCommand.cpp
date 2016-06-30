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

    this->process_manager = std::unique_ptr<ProcessManager>(new ProcessManager);
}

ShowCommand::~ShowCommand()
{
}

void ShowCommand::Run(void)
{
    if ( this->regex_map.Test("all", this->arguments) ) {
        std::cout << "You gave the all option" << std::endl;
    } else if ( this->regex_map.Test("name", this->arguments) ) {
        std::cout << "You gave the name: option" << std::endl;
    } else {
        std::cout << "Unknown option...try help" << std::endl;
    }

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::ShowAll()
{

}

} // End Commands
} // End CLI
} // End LixProc
