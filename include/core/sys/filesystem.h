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
#include <vector>

namespace Telemetry {
namespace Core {
namespace Sys {

class FileSystem {
 public:
  FileSystem() : label(""), size(0), used(0), avail(0) {};
  FileSystem(std::string label, std::uint64_t size, std::uint64_t used, std::uint64_t avail)
      : label(label), size(size), used(used), avail(avail) {};

  /**
   * Get the filesystem's label.
   *
   * @return
   */
  const std::string &GetLabel() const {
    return this->label;
  };

  /**
   * Get the filesystem's size in kbs.
   *
   * @return
   */
  const std::uint64_t &GetSize() const {
    return this->size;
  }

  /**
   * Get the filesystem's used amount in kbs.
   *
   * @return
   */
  const std::uint64_t &GetUsed() const {
    return this->used;
  };

  /**
   * Get the filesystem's available amount in kbs.
   *
   * @return
   */
  const std::uint64_t &GetAvailable() const {
    return this->avail;
  };

  float GetRelativeSize() const
  {
    return 1.23;
  }

  float GetRelativeUsed() const {
    return this->GetRelativeAmount(static_cast<float>(this->GetUsed()));
  }

  float GetRelativeAvailable() const
  {
    return this->GetRelativeAmount(static_cast<float>(this->GetAvailable()));
  }

  static void SetTotalFileSystemSize(std::uint64_t size)
  {
    FileSystem::total_size = size;
  }

  static std::uint64_t GetTotalFileSystemSize()
  {
    return FileSystem::total_size;
  }

 private:
  std::string label;
  std::uint64_t size;
  std::uint64_t used;
  std::uint64_t avail;
  static std::uint64_t total_size;

  /**
   * Get a size relative to the entire filesystem's size.
   *
   * @param amount
   *
   * @return
   */
  float GetRelativeAmount(float amount) const {
    return this->GetRelativeAmount(
        amount,
        static_cast<float>(this->GetSize())
    );
  }

  /**
   * Get the relative size of one number to another.
   *
   * @param relative
   * @param of
   *
   * @return
   */
  float GetRelativeAmount(float relative, float of) const {
    return of == 0.0 ? 0.0 : (relative / of) * 100.00;
  }

};

// Expose some iterators for convenience's sake.
typedef std::vector<FileSystem>::const_iterator FileSystemIterator;
typedef std::pair<FileSystemIterator, FileSystemIterator> FileSystemIterators;

}
}
}

#endif //TELEMETRY_CORE_SYS_FILESYSTEM_H
