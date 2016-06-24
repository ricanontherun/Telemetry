#ifndef CLI_COMMANDS_COMMAND_H
#define CLI_COMMANDS_COMMAND_H

#include <string>
#include <vector>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class Command
{
    public:
        Command(void) {};
        Command(std::vector<std::string> &arguments);

        virtual void Run(void) = 0;
        void SetArguments(std::vector<std::string> &arguments);
    protected:
        std::vector<std::string> arguments;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
