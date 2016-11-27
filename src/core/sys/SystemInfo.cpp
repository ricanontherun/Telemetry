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

#include <shell.h>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

namespace LixProc {

struct sysinfo SystemInfo::sys_info;

int SystemInfo::pagesize = 0;

bool SystemInfo::captured = false;

SystemInfo::CPU SystemInfo::cpu = SystemInfo::CPU();

std::unordered_map<
    std::string, std::set<std::string>
> SystemInfo::key_map = {
    {
        "Architecture",
        {
            "architecture"
        }
    },
    {
        "Model",
        {
            "model name"
        }
    }
};

void SystemInfo::Capture() {
  if (SystemInfo::captured) {
    return;
  }

  SystemInfo::CaptureSystemStatistics();

  SystemInfo::CapturePageSize();

  SystemInfo::CaptureCPU();

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

void SystemInfo::CaptureCPU() {
  std::string out;

  if (!RunInShell("lscpu", out)) {
    return;
  }

  std::vector<std::string> lines;
  lines.reserve((std::size_t) std::count(out.begin(), out.end(), '\n'));

  boost::split(lines, out, boost::is_any_of("\n"), boost::token_compress_on);

  for (auto const &line : lines) {
    // First we need to isolate the key:value pairs from
    // lscpu output.
    std::size_t first_colon = line.find(':');

    if (first_colon == std::string::npos) { // TODO: Why does this happen?
      continue;
    }

    if (first_colon > line.length() - 1) {
      continue;
    }

    std::string key = line.substr(0, first_colon);
    std::string value = line.substr(first_colon + 1); // This could technically cause an out of bounds.

    // Trim
    boost::algorithm::trim(value);

    // Lowercase the key
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    if (SystemInfo::key_map["Architecture"].count(key) != 0) {
      SystemInfo::cpu.architecture = value;
    }

    if (SystemInfo::key_map["Model"].count(key) != 0) {
      SystemInfo::cpu.model_name = value;
    }
  }
}

const SystemInfo::CPU &SystemInfo::GetCPU() {
  return SystemInfo::cpu;
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
