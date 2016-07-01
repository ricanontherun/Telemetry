#include <string>
#include <sstream>

#include <utils/str.h>

#include <string.h>

namespace LixProc
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
        elems.push_back(item);
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

uint64_t ConvertToInteger(char *string)
{
    char *end;
    return strtol(string, &end, 10);
}

} // End Utils
} // End LixProc
