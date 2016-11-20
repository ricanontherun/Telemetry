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
#include <core/sys/SystemUser.h>

#include <unistd.h>

namespace LixProc {

uid_t SystemUser::uid = 0;

gid_t SystemUser::gid = 0;

uid_t SystemUser::GetUserID() {
  if (SystemUser::uid == 0) {
    SystemUser::uid = getuid();
  }

  return SystemUser::uid;
}

gid_t SystemUser::GetGroupID() {
  if (SystemUser::gid == 0) {
    SystemUser::gid = getgid();
  }

  return SystemUser::gid;
}

} // End LixProc
