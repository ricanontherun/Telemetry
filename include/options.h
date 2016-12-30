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
#ifndef TELEMETRY_OPTIONS_H
#define TELEMETRY_OPTIONS_H

#include <string>

namespace Telemetry
{

/**
 * Enum of all possible resources reported by Telemetry.
 */
enum Resource
{
  NONE = 0,
  ALL = 1,
  SYSTEM = 2,
  PROCESSES = 4,
  DISK = 8
};

enum SizeUnit {
  KB = 0,
  MB = 0
};

struct Options {
  int resources = Resource::NONE;
  int unit = SizeUnit::KB;
};

}

#endif //TELEMETRY_OPTIONS_H
