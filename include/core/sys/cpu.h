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
#ifndef TELEMETRY_CORE_SYS_CPU_H
#define TELEMETRY_CORE_SYS_CPU_H

#include <map>
#include <set>

namespace Telemetry {

namespace Core {

namespace Sys {

class CPU {
 public:
  CPU();
  void Read();

  const std::string &GetArchitecture() const;
  const std::string &GetModel() const;
  const std::string &GetCPUCount() const;

 private:
  const char *command_string = "lscpu";

  std::string architecture;
  std::string model_name;

  std::string cpus;
  std::string ghz;

  // This structure maps a keyword to a set of possible
  // output keys. Using an ordered set gives us O(logn) lookups.
  static std::map<
      std::string, std::set<std::string>
  > key_map;

};

} // Sys
} // Core
} // Telemetry

#endif //TELEMETRY_CORE_SYS_CPU_H
