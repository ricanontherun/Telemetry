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
#ifndef TELEMETRY_CORE_SYS_INFO_H
#define TELEMETRY_CORE_SYS_INFO_H

#include <core/sys/cpu.h>

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

namespace Telemetry {

class SystemInfo {
 public:

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

  static const Core::Sys::CPU &GetCPU();
 private:
  static struct sysinfo sys_info;
  static int pagesize;
  static bool captured;
  static Core::Sys::CPU cpu;

  static void CaptureSystemStatistics();
  static void CapturePageSize();
  static void CaptureCPU();
};

}

#endif
