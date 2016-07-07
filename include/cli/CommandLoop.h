#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H

#include <map>

#include <utils/command.h>
#include <cli/CommandFactory.h>
#include <cli/commands/Command.h>

namespace LixProc
{
namespace CLI
{

class CommandLoop
{
    public:
        void InitMainLoop(void);

    protected:
        static const std::string welcome;
        static const std::string line_prefix;

        void ParseCommand(
            std::string command_str,
            LixProc::Utils::Command &command
        );

        bool ValidateCommand(LixProc::Utils::Command &command);

    private:
        void ShowWelcome() const;
};

} // End CLI
} // End LixProc

#endif
