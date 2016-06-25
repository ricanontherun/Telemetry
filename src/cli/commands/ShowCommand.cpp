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

void ShowCommand::Run(void)
{
    this->ParseArguments(this->arguments);

    std::cout << "Running the show command" << std::endl;
}

void ShowCommand::ParseArguments(std::string arguments)
{
}

std::regex ShowCommand::GetArgumentRegex(ArgumentRegex name) const
{

    return this->argument_regex_map[name];
}

} // End Commands
} // End CLI
} // End LixProc
