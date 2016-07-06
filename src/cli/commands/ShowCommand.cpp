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
        this->Show();
    } else if ( this->regex_map.Test("name", this->arguments) ) {
        std::size_t found = this->arguments.find_first_of(":");
        std::string name = this->arguments.erase(0, found + 1);

        this->Show(name);
    } else {
        std::cout << "Unknown option...try help" << std::endl;
    }

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::Show() const
{
    ProcessIterators iterators = ProcessManager::Load();

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}

void ShowCommand::Show(const std::string &name) const
{
    ProcessIterators iterators = ProcessManager::Load(name);

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}

} // End Commands
} // End CLI
} // End LixProc
