#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H

#include <cli/commands/Command.h>
#include <utils/command.h>

namespace SystemMonitor
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

        enum class Commands {
            SHOW = 0
        };

        void ParseCommand(std::string command_str, SystemMonitor::Utils::Command &command);
};

} // End CLI
} // End SystemMonitor

#endif
