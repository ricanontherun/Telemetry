#ifndef CORE_UTIL_FILE_H
#define CORE_UTIL_FILE_H

namespace SystemMonitor
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
bool FileExists(const std::string path);

/**
 * Get the first line of a file.
 *
 * @param path
 *
 */
std::string FileGetFirstLine(std::string path);

} // End File
} // End Utils
} // End SystemMonitor

#endif
