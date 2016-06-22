#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

#include <cli/commands/CommandFactory.h>
#include <cli/commands/Command.h>
#include <cli/CommandLoop.h>

using LixProc::CLI::Commands::Command;
using LixProc::CLI::Commands::CommandFactory;

int main()
{
    std::unique_ptr<Command> ptr = CommandFactory::Make("help");
    ptr->Run();
}
