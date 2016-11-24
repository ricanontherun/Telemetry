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
#include <core/sys/SystemInfo.h>
#include <Collectors/ProcessCollector.h>

#include <fstream>
#include <Collectors/SystemCollector.h>

int main(int argc, char **argv)
{
  // Parse the CLI arguments.
  LixProc::options options;
  LixProc::parse_options(argc, argv, &options);

  nlohmann::json j = nlohmann::json::object();

  if ( options.resources & static_cast<int>(LixProc::Resource::PROCESSES) ) {
    LixProc::Collectors::ProcessCollector collector;
    collector.load();
    collector.toJSON(j);
  }

  if (options.resources & static_cast<int>(LixProc::Resource::SYSTEM)) {
    LixProc::Collectors::SystemCollector system_collector;
    system_collector.load();
    system_collector.toJSON(j);
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
    std::cout << j.dump(2) << "\n";
  }

  return EXIT_SUCCESS;
}
