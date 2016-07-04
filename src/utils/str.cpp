#include <string>

#include <utils/str.h>

namespace LixProc
{
namespace Utils
{

uint64_t ConvertToInteger(char *string)
{
    char *end;
    return strtol(string, &end, 10);
}

} // End Utils
} // End LixProc
