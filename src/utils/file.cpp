#include <fstream>

namespace LixProc
{
namespace Utils
{
namespace File
{

/**
 * Does a file exist.
 *
 * @param path
 *
 * @return
 */
bool FileExists(const std::string path)
{
    std::ifstream file(path);
    bool exists = file.good();
    file.close();

    return exists;
}

/**
 * Get the first line of a file.
 *
 * @param path
 *
 */
std::string FileGetFirstLine(std::string path)
{
    if ( !FileExists(path) )
    {
        // TODO: Don't be afraid to throw run_time exceptions!
        return "";
    }

    std::ifstream file(path);
    std::string line;

    std::getline(file, line);

    file.close();

    return line;
}

} // End File
} // End Utils
} // End LixProc
