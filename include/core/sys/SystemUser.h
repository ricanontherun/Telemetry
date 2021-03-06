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
#ifndef TELEMETRY_CORE_SYS_USER_H
#define TELEMETRY_CORE_SYS_USER_H

#include <sys/types.h>

namespace Telemetry
{

class SystemUser {
    public:
        static uid_t GetUserID();
        static gid_t GetGroupID();
    private:
        static uid_t uid;
        static gid_t gid;

};

} // End Telemetry

#endif
