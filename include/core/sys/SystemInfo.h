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
#ifndef CORE_SYS_SYSTEMINFO_H
#define CORE_SYS_SYSTEMINFO_H

#include <unistd.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unordered_map>
#include <set>

namespace LixProc {

class SystemInfo {
 public:

  struct CPU {
    CPU() : num_cpus(0), ghz(0) {}

    std::string architecture;
    std::string model_name;

    std::uint8_t num_cpus;
    std::uint32_t ghz;
  };

  /**
   * Capture information about the host machine.
   */
  static void Capture();

  /**
   * Get the host machine's amount of RAM in bytes.
   */
  static uint64_t GetTotalSystemMemory();

  /**
   * Get the host system's page size.
   */
  static int GetPageSize();

  static const CPU &GetCPU();
 private:
  static struct sysinfo sys_info;
  static int pagesize;
  static bool captured;
  static CPU cpu;

  // This structure maps a keyword to a set of possible
  // output keys. Using an ordered set gives us O(logn) lookups.
  static std::unordered_map<
      std::string, std::set<std::string>
  > key_map;

  static void CaptureSystemStatistics();
  static void CapturePageSize();
  static void CaptureCPU();
};

}

#endif
