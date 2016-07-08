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
#ifndef CORE_UTIL_FILE_H
#define CORE_UTIL_FILE_H

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
bool FileExists(const std::string &path);

/**
 * Get the first line of a file.
 *
 * @param path
 *
 */
std::string FileGetFirstLine(std::string path);

} // End File
} // End Utils
} // End LixProc

#endif
