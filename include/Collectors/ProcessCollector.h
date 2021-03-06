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
#ifndef TELEMETRY_COLLECTOR_PROCESS_H
#define TELEMETRY_COLLECTOR_PROCESS_H

#include <interfaces/Collector.h>
#include <core/process/Process.h>

namespace Telemetry {

class Results;

namespace Collectors {

class ProcessCollector : public Interfaces::Collector {
 public:

  /**
   * Collect all active processes into results.
   *
   * @param results
   */
  void collect(Results & results);
 private:
  // Base process directory path.
  std::string proc_root;

  void Load(uint64_t pid, Results & results) noexcept;
};

}

}

#endif //TELEMETRY_COLLECTOR_PROCESS_H
