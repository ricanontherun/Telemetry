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
#ifndef TELEMETRY_ALL_H
#define TELEMETRY_ALL_H

#include <json.hpp>

namespace Telemetry
{

enum Resource
{
  EMPTY     = 0,
  ALL       = 2 | 4,  // All supported resources will be collected.
  SYSTEM    = 2,      // Brief system related info, CPU, Memory, Hard disk space?
  PROCESSES = 4,      // System processes will be collected.
};

class Unit
{
 private:
  int flags = Resource::EMPTY;

  void QuerySystem(nlohmann::json & json);
 public:
  Unit(int flags = Resource::ALL);
  void Read();
  void Read(std::string & output);

};

}

#endif //TELEMETRY_ALL_H
