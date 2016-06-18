#include <iostream>
#include <string>
#include <vector>

#include <cli/commands/TestCommand.h>

int main()
{
    std::vector<std::string> arguments {"arg1", "arg2"};
    LixProc::CLI::Commands::TestCommand command(arguments);;
}
