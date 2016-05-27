#include <string>
#include <sstream>

#include "str.h"

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
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;

    while ( getline(ss, item, delim) ) {
        // In case of no delimiters being found, the entire string s is returned.
        // So, we need to catch case.
        if ( item.compare(s) != 0 ) {
            elems.push_back(item);
        }
    }

    return elems;
}

/**
 * Split a string at it delim into a vector<string>.
 *
 * @param s
 * @param delim
 *
 * @return
 */
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);

    return elems;
}

} // End Utils
} // End SystemMonitor
