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

#include <iostream>

#include <Collectors/ProcessCollector.h>
#include <options.h>
#include <core/sys/SystemInfo.h>
#include <fstream>

int main(int argc, char **argv)
{

  // Parse the CLI arguments.
  LixProc::options options;
  LixProc::parse_options(argc, argv, &options);

  nlohmann::json j;

  // Depending on the resources requested, query the system and append the
  // results to the json object.
  if ( options.resources & static_cast<int>(LixProc::Resource::PROCESSES) ) {
    LixProc::Collectors::ProcessCollector collector;
    collector.Load();
    collector.toJSON(j);
  }

  if (options.resources & static_cast<int>(LixProc::Resource::SYSTEM)) {
    j["system"] = {
        {"memory", LixProc::SystemInfo::GetTotalSystemMemory()},
    };
  }

  if (!options.output_path.empty()) {
    std::ofstream output_file(options.output_path);

    if (!output_file.good()) {
      std::cerr << "Failed opening file '" << options.output_path << "', " << strerror(errno) << "\n";
      return EXIT_FAILURE;
    }

    output_file << j;

    output_file.close();
  } else {
    std::cout << j << "\n";
  }

  return EXIT_SUCCESS;
}
