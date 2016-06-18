#ifndef CLI_COMMANDS_TEST_COMMAND_H
#define CLI_COMMANDS_TEST_COMMAND_H

#include <cli/commands/Command.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class TestCommand : public Command
{
    public:
        TestCommand(void);
        TestCommand(std::vector<std::string> &arguments);
        void Run(void);
};

} // End Commands
} // End CLI
} // End LixProc

#endif
