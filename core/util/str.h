#ifndef CORE_UTIL_STR_H
#define CORE_UTIL_STR_H

#include <vector>

namespace SystemMonitor
{
    namespace Utils
    {
        std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
        std::vector<std::string> split(const std::string &s, char delim);
    }
}

#endif
