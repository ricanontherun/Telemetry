#ifndef CORE_UTILS_COMMAND_H
#define CORE_UTILS_COMMAND_H

#include <string>
#include "../process/Process.h"

namespace SystemMonitor
{
namespace Utils
{

using Core::Process;

/**
 * Parse a Linux process command into it's path, executable and arguments
 *
 * @param command_str
 * @param command
 *
 * @return
 */
bool ExtractCommandElements(std::string command_str, Process::Command &command);

} // End Utils
} // End SysteMonitor

#endif
