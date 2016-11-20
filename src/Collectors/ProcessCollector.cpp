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

#include <string.h>
#include <sys/stat.h>
#include <iostream>
#include <core/sys/SystemUser.h>
#include <dirent.h>
#include <utils/str.h>

namespace LixProc {

namespace Collectors {

/**
 * @brief Load the process list.
 */
ProcessIterators ProcessCollector::Load() {
  this->LoadProcessList();

  return this->MakeIterators();
}

void ProcessCollector::Load(uint64_t pid) {
  struct stat info;
  int stat_i;

  std::string dir_name = std::to_string(pid);
  std::string full_process_path = Core::Process::PD_BASE + dir_name;

  stat_i = stat(full_process_path.c_str(), &info);

  if (stat_i == -1) {
    // TODO: Determine appropriate action. If the file doesn't exist,
    // that probably shouldn't be an error. Else, write to a log?
    std::cout << strerror(errno) << std::endl;
  }

  // Are we the owner of the process?
  if (SystemUser::GetUserID() != info.st_uid || SystemUser::GetGroupID() != info.st_gid) {
    return;
  }

  try {
    this->processes[pid] = std::make_unique<Core::Process>(pid);
  } catch (std::runtime_error &error) {
    std::cerr << error.what() << std::endl;
  }
}

ProcessIterators ProcessCollector::Load(const std::string &name) {
  // First, load all processes.
  this->Load();

  Utils::Command command;

  // Iterate and erase any processes whose executable names don't match the name filter.
  for (auto it = this->processes.begin(); it != this->processes.end();) {
    command = it->second->GetCommand();

    if (command.name != name) {
      it = this->processes.erase(it);
    } else {
      it++;
    }
  }

  return this->MakeIterators();
}


/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

/**
 * @brief Load the process list.
 */
void ProcessCollector::LoadProcessList() {

  DIR *d;
  struct dirent *de;

  d = opendir(Core::Process::PD_BASE.c_str());

  // If we can't read from /proc something is very wrong.
  if (d == NULL) {
    closedir(d);
  }

  while ((de = readdir(d))) {
    uint64_t dir_val = 0;
    if (de->d_type != DT_DIR || !(dir_val = LixProc::Utils::ConvertToInteger(de->d_name))) {
      continue;
    }

    try {
      this->Load(dir_val);
    } catch (std::runtime_error &e) {

    }
  }

  closedir(d);
}

ProcessIterators ProcessCollector::MakeIterators() {
  return std::make_pair(
      this->processes.begin(),
      this->processes.end()
  );
}

void ProcessCollector::toJSON() {
  std::cout << "Storing the data in a json element\n";
}

}

}