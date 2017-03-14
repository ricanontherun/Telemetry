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

#include <cstdint>

namespace Telemetry
{

enum class Resource
{
  ALL         = 1,
  MEMORY      = 2,
  PROCESSES   = 4,
  FILESYSTEMS = 8,
  CPU         = 16
};

enum class SizeUnit {
  KB = 0,
  MB = 1
};

struct Options {
  std::uint16_t resources = 0;
  SizeUnit unit = SizeUnit::KB;
};

} // End Telemetry

#endif //TELEMETRY_OPTIONS_H
