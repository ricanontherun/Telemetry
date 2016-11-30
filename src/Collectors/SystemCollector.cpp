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

namespace LixProc {
namespace Collectors {

void SystemCollector::toJSON(nlohmann::json &json) const {
  json["system"] = {
      {"memory", SystemInfo::GetTotalSystemMemory()}
  };

  // cpu
  const Core::CPU &cpu = SystemInfo::GetCPU();
  json["system"]["cpu"] = nlohmann::json::object();
  json["system"]["cpu"]["model"] = cpu.GetModel();
  json["system"]["cpu"]["architecture"] = cpu.GetArchitecture();
  json["system"]["cpu"]["cpus"] = cpu.GetCPUCount();
}

void SystemCollector::load() {
  LixProc::SystemInfo::Capture();
}

}
}