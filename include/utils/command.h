#ifndef CORE_UTILS_COMMAND_H
#define CORE_UTILS_COMMAND_H

#include <string>

namespace SystemMonitor
{
namespace Utils
{

struct Command {
    std::string path;
    std::string executable;
    std::string arguments;
};

/**
 * Parse a command string in the form "path/to/executable arguments" into a Command object.
 *
 * Example:
 *  ParseCommandString("/path/to/executable --rf --arg1=yes --arg2=no", command);
 *  ...
 *  command.path = /path/to/
 *  command.executable = executable
 *  command.arguments = -rf --arg1=yes --arg2=no
 *
 * @param command_str
 * @param command
 *
 * @return
 */
bool ParseCommandString(std::string command_str, Command &command);

} // End Utils
} // End SysteMonitor

#endif
