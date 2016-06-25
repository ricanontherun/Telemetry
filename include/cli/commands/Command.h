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

        virtual void Run(void) = 0;
        void SetArguments(std::string arguments);
    protected:
        std::string arguments;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
