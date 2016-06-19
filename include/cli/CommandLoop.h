#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H

#include <utils/command.h>

namespace SystemMonitor
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

        void ParseCommand(std::string command_str, SystemMonitor::Utils::Command &command);
};

} // End CLI
} // End SystemMonitor

#endif
