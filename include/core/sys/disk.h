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
#ifndef TELEMETRY_CORE_SYS_DISK_H
#define TELEMETRY_CORE_SYS_DISK_H

#include <core/sys/filesystem.h>
#include <interfaces/Readable.h>

#include <utility>
#include <vector>

namespace Telemetry {
namespace Core {
namespace Sys {

class Disk : public Interfaces::Readable {
 private:
  std::size_t column_count = 4;
  const char *command_string = "df --output=source,size,used,avail";

  std::vector<FileSystem> filesystems;

  void ReadFileSystems();
  void ReadDiskUsage();
 public:
  void Read();

  FileSystemIterators GetFileSystemIterators() const;
};

} // Sys
} // Core
} // Telemetry

#endif //TELEMETRY_CORE_SYS_DISK_H
