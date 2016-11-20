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

int main(int argc, char **argv)
{

  LixProc::options options;

  LixProc::parse_options(argc, argv, &options);

  nlohmann::json j;

  if ( options.resources & static_cast<int>(LixProc::Resource::PROCESSES) ) {
    std::cout << "Collecting process info\n";

    LixProc::Collectors::ProcessCollector collector;
    collector.Load();
    collector.toJSON(j);
  }

  if (options.resources & static_cast<int>(LixProc::Resource::SYSTEM)) {
    std::cout << "Collecting system info\n";
  }

  if (!options.output_path.empty()) {
    // Collect and put to json
  } else {
    // Collect each resource and print.
  }

  return EXIT_SUCCESS;
}
