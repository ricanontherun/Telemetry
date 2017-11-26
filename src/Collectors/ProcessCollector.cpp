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
#include <Collectors/ProcessCollector.h>

#include <utils/str.h>
#include <core/sys/SystemUser.h>
#include <results.h>

#include <sys/stat.h>
#include <dirent.h>

namespace Telemetry {

namespace Collectors {

void ProcessCollector::collect(Results & results) {
  DIR *d = opendir(Core::Process::PD_BASE.c_str());

  if (!d) {
    std::cerr << "Failed to open " + Core::Process::PD_BASE << "\n";
    return;
  }

  struct dirent *de;

  while ((de = readdir(d))) {
    if (de->d_type != DT_DIR) {
      continue;
    }

    uint64_t pid = 0;

    // Process directories are integers, thus, if we can't convert the directory name to an integer it's not a pid directory.
    if (!(pid = Telemetry::Utils::ConvertToInteger(de->d_name))) {
      continue;
    }

    Load(pid, results);
  }

  closedir(d);
}

void ProcessCollector::Load(uint64_t pid, Results & results) noexcept {
  struct stat info;

  std::string dir_name = std::to_string(pid);
  std::string full_process_path = Core::Process::PD_BASE + dir_name;

  if (stat(full_process_path.c_str(), &info) == -1) {
      std::cerr << "Failed to stat file " + full_process_path << "\n";
      return;
  }

  try {
    results.processes[pid] = std::make_unique<Core::Process>(pid);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

} // Namespace Collectors

} // Namespace Telemetry
