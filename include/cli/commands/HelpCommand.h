#ifndef CLI_COMMAND_HELP_COMAND_H
#define CLI_COMMAND_HELP_COMAND_H

#include <cli/commands/Command.h>

namespace LixProc
{
namespace CLI
{
namespace Commands
{

class HelpCommand : public Command
{
    public:
        HelpCommand();
        void Run(void);

    private:
        void ShowGeneralHelp() const;
};

} // End Commands
} // End CLI
} // End LixProc

#endif
