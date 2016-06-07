#ifndef CORE_UTILS_COMMAND_H
#define CORE_UTILS_COMMAND_H

#include <string>

// This doesn't make sense. Get this dependency out of here.
#include <core/process/Process.h>

namespace SystemMonitor
{
namespace Utils
{

using Core::Process;

/**
 * Parse a Linux process string, found in /proc/PID/cmdline, into
 * it's respective path, executable and arguments.
 *
 * Example:
 *  /path/to/executable --rf --arg1=yes --arg2=no
 *  =>
 *  command.path = /path/to/ command.executable = executable command.arguments = -rf --arg1=yes --arg2=no
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
