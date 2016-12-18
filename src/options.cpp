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
#include <options.h>
#include <unordered_map>
#include <iostream>

namespace Telemetry
{

void parse_options(int argc, char **argv, struct options *options)
{
  for (int i = 1; i < argc; i++) {
    const char *option = argv[i];
    if (option[0] == '-') {
      parse_resource_flags(option, options);
    } else {
      options->output_path = std::string(option);
    }
  }
}

static void parse_resource_flags(const char *flag, struct options *options)
{
  std::unordered_map<char, Resource> resource_map = {
      {'s', Resource::SYSTEM},
      {'p', Resource::PROCESSES}
  };

  for (int i = 1; flag[i] != '\0'; i++ ) {
    auto resource = resource_map.find(flag[i]);

    if (resource != resource_map.end()) {
      options->resources |= static_cast<int>(resource->second);
    }
  }
}

}