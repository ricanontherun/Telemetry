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

ShowCommand::~ShowCommand()
{
}

void ShowCommand::Run(void)
{
    if ( this->regex_map.Test("all", this->arguments) ) {
        this->ShowAll();
    } else if ( this->regex_map.Test("name", this->arguments) ) {
        std::cout << "You gave the name: option" << std::endl;
    } else {
        std::cout << "Unknown option...try help" << std::endl;
    }

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::ShowAll()
{
    ProcessIterators iterators = ProcessManager::Load();

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}

} // End Commands
} // End CLI
} // End LixProc
