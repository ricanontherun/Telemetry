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
#include <core/sys/SystemInfo.h>

namespace LixProc {

struct sysinfo SystemInfo::sys_info;
int SystemInfo::pagesize = 0;
bool SystemInfo::captured = false;

void SystemInfo::Capture() {
  if (SystemInfo::captured) {
    return;
  }

  SystemInfo::CaptureSystemStatistics();

  SystemInfo::CapturePageSize();

  SystemInfo::captured = true;
}

uint64_t SystemInfo::GetTotalSystemMemory() {
  SystemInfo::Capture();

  return SystemInfo::sys_info.totalram * SystemInfo::sys_info.mem_unit;
}

int SystemInfo::GetPageSize() {
  SystemInfo::Capture();

  return SystemInfo::pagesize;
}

/**
 *--------------------------------------------------
 * Private
 *--------------------------------------------------
 */

void SystemInfo::CaptureSystemStatistics() {
  int reti = sysinfo(&SystemInfo::sys_info);

  if (reti == -1) {
    std::cerr << "sysinfo call failed. Exiting.." << std::endl;
    exit(EXIT_FAILURE);
  }
}

void SystemInfo::CapturePageSize() {
  SystemInfo::pagesize = getpagesize();
}

} // End
