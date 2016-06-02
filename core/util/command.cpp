#include <iostream>
#include <string>
#include <vector>

#include "str.h"
#include "command.h"

namespace SystemMonitor
{
namespace Utils
{

bool ExtractCommandElements(std::string command_str, Process::Command &command)
{
    std::vector<std::string> process_command_parts = split(command_str, ' ');

    if ( process_command_parts.size() == 0 )
    {
        return false;
    }

    // We're assuming the first vector element is the path + executable
    std::string full_path = process_command_parts.front();

    size_t first_space = command_str.find_first_of(' ');

    command.arguments = first_space != std::string::npos ? command_str.substr(first_space + 1) : "";

    size_t slash_index = full_path.find_last_of('/');

    command.path = slash_index != std::string::npos ? full_path.substr(0, slash_index + 1) : "";

    size_t slice_index = slash_index != std::string::npos ? slash_index + 1 : 0;

    command.executable = full_path.substr(slice_index);

    return true;
}

} // End Utils
} // End SysteMonitor
