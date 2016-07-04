#include <utils/command.h>

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include <utils/str.h>

namespace LixProc
{
namespace Utils
{

bool ParseCommandString(std::string command_str, Command &command)
{
    std::vector<std::string> chunks;
    boost::split(chunks, command_str, boost::is_any_of(" "));

    if ( chunks.size() == 0 )
    {
        return false;
    }

    // We're assuming the first vector element is the path + name
    std::string full_path = chunks.front();

    size_t first_space = command_str.find_first_of(' ');

    command.arguments = first_space != std::string::npos ? command_str.substr(first_space + 1) : "";

    size_t slash_index = full_path.find_last_of('/');

    command.path = slash_index != std::string::npos ? full_path.substr(0, slash_index + 1) : "";

    size_t slice_index = slash_index != std::string::npos ? slash_index + 1 : 0;

    command.name = full_path.substr(slice_index);

    return true;
}

} // End Utils
} // End SysteMonitor
