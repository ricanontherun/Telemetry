#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H

#include <map>

#include <cli/commands/Command.h>
#include <cli/CommandFactory.h>
#include <utils/command.h>

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
        static std::map<std::string, LixProc::CLI::CommandFactory::CommandEnum> command_map;

        void ParseCommand(
            std::string command_str,
            LixProc::Utils::Command &command
        );

        bool ValidateCommand(LixProc::Utils::Command &command);
};

} // End CLI
} // End LixProc

#endif
