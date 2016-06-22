#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H

#include <cli/commands/Command.h>
#include <utils/command.h>

namespace LixProc
{
namespace CLI
{

class CommandLoop
{
    public:
        void InitMainLoop(void);
        static LixProc::CLI::Commands::Command *Instance(std::string command);

    protected:
        static const std::string welcome;
        static const std::string line_prefix;
        static std::vector<std::string> commands;

        void ParseCommand(
            std::string command_str,
            LixProc::Utils::Command &command
        );

        bool ValidateCommand(LixProc::Utils::Command &command);
};

} // End CLI
} // End LixProc

#endif
