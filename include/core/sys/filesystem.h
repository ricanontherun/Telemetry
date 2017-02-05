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
#ifndef TELEMETRY_CORE_SYS_FILESYSTEM_H
#define TELEMETRY_CORE_SYS_FILESYSTEM_H

#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>

namespace Telemetry {
namespace Core {
namespace Sys {

class FileSystem {
 private:
  std::string source;
  std::uint64_t size;
  std::uint64_t used;
  std::uint64_t avail;

 public:
  FileSystem() : source(""), size(0), used(0), avail(0) {};
  FileSystem(std::string source, std::uint64_t size, std::uint64_t used, std::uint64_t avail)
      : source(source), size(size), used(used), avail(avail) {};

  const std::string &GetSource() const {
    return this->source;
  };

  const std::uint64_t &GetSize() const {
    return this->size;
  }

  const std::uint64_t &GetUsed() const {
    return this->used;
  };

  float GetPercentUsed() const {
    float size = static_cast<float>(this->GetSize());

    if ( size == 0.0 ) {
      return 0.0;
    }

    float used = static_cast<float>(this->GetUsed());

    return (used / size) * 100.00;
  }

  const std::uint64_t &GetAvailable() const {
    return this->avail;
  };
};

}
}
}

#endif //TELEMETRY_CORE_SYS_FILESYSTEM_H
