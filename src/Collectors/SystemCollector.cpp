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
#include <Collectors/SystemCollector.h>
#include <core/sys/SystemInfo.h>

namespace Telemetry {
namespace Collectors {

void SystemCollector::toJSON(nlohmann::json &json) const {
  json["system"] = {
      {"memory", SystemInfo::GetTotalSystemMemory()}
  };

  // cpu
  const Core::Sys::CPU &cpu = SystemInfo::GetCPU();
  json["system"]["cpu"] = nlohmann::json::object();
  json["system"]["cpu"]["model"] = cpu.GetModel();
  json["system"]["cpu"]["architecture"] = cpu.GetArchitecture();
  json["system"]["cpu"]["cpus"] = cpu.GetCPUCount();

  // Disk
  std::uint64_t size = 0;
  std::uint64_t used = 0;

  Core::Sys::FileSystemIterators iterators = SystemInfo::GetDisk().GetFileSystemIterators();

  for (auto it = iterators.first; it != iterators.second; it++) {
    size += it->GetSize();
    used += it->GetUsed();

  }
}

void SystemCollector::load() {
  Telemetry::SystemInfo::Capture();
}

}
}