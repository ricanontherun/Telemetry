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
#include <core/sys/cpu.h>

#include <utils/shell.h>

#include <vector>
#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

namespace Telemetry {
namespace Core {
namespace Sys {

std::map<
    std::string, std::set<std::string>
> Sys::CPU::key_map = {
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
    },
    {
        "CPU Count",
        {
            "cpu(s)"
        }
    }

};

CPU::CPU() : cpus(""), ghz("") {

}

void CPU::Read() {
  std::string out;

  if (!RunInShell(this->command_string, out)) {
    return;
  }

  std::vector<std::string> lines;
  lines.reserve((std::size_t) std::count(out.begin(), out.end(), '\n'));

  boost::split(lines, out, boost::is_any_of("\n"), boost::token_compress_on);

  for (auto const &line : lines) {
    std::size_t first_colon = line.find(':');

    if (first_colon == std::string::npos) { // TODO: Why does this happen?
      continue;
    }

    if (first_colon > line.length() - 1) {
      continue;
    }

    std::string key = line.substr(0, first_colon);
    std::string value = line.substr(first_colon + 1);

    // Trim
    boost::algorithm::trim(value);

    // Lowercase the key
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    if (CPU::key_map["Architecture"].count(key) != 0) {
      this->architecture = value;
    }

    if (CPU::key_map["Model"].count(key) != 0) {
      this->model_name = value;
    }

    if (CPU::key_map["CPU Count"].count(key) != 0) {
      this->cpus = value;
    }
  }
}

const std::string &CPU::GetArchitecture() const {
  return this->architecture;
}

const std::string &CPU::GetModel() const {
  return this->model_name;
}

const std::string &CPU::GetCPUCount() const {
  return this->cpus;
}

} // Namespace Sys
} // Namespace Core
} // Namespace Telemetry
