#ifndef CLI_COMMANDS_SHOW_COMMAND_H
#define CLI_COMMANDS_SHOW_COMMAND_H

#include <cli/commands/Command.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class ShowCommand : public Command
{
    public:
        ShowCommand(void);
        void Run();
};

}
}
}
#endif
