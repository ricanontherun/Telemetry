#ifndef CORE_UTIL_STR_H
#define CORE_UTIL_STR_H

#include <vector>

namespace SystemMonitor
{
namespace Utils
{


/**
 * Split a string on a delim, placing the parts into elems.
 *
 * @param s
 * @param delim
 * @param elems
 *
 * @return
 */
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

/**
 * Split a string at it delim into a vector<string>.
 *
 * @param s
 * @param delim
 *
 * @return
 */
std::vector<std::string> split(const std::string &s, char delim);

} // End Utils
} // End SystemMonitor

#endif
