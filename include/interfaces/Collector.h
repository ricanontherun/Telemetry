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
#ifndef TELEMETRY_INTERFACES_COLLECTOR_H
#define TELEMETRY_INTERFACES_COLLECTOR_H

#include <options.h>

namespace Telemetry
{

class Results;

namespace Interfaces {

class Collector
{
 public:
  Collector(Results * results) : results(results) {};

  virtual void load() = 0;

  void setOptions(Options options) {
    this->options = options;
  }

 protected:
  Options options;
  Results * results;
};

}
}

#endif //TELEMETRY_INTERFACES_COLLECTOR_H
