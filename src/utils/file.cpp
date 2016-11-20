// Copyright (C) 2016 Christian Roman
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <fstream>
#include <iostream>
#include <memory>

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
bool FileExists(const std::string &path)
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

    std::size_t length = BUFSIZ;
    std::ifstream file(path);

    std::unique_ptr<char []> buffer = std::make_unique<char []>(length);

    file.read(buffer.get(), length);

    file.close();

    std::string line(buffer.get());

    return line;
}

} // End File
} // End Utils
} // End LixProc
