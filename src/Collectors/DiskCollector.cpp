#include <Collectors/DiskCollector.h>
#include <results.h>
#include <utils/shell.h>
#include <core/sys/filesystem.h>

#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

namespace Telemetry {
namespace Collectors {

void DiskCollector::collect(Results & results) {
  std::string output;

  // Run the command.
  if (!RunInShell(this->command_string, output)) {
    return;
  }

  // Split the output in lines.
  std::vector<std::string> lines;
  lines.reserve((std::size_t) std::count(output.begin(), output.end(), '\n'));
  boost::split(lines, output, boost::is_any_of("\n"), boost::token_compress_on);

  // At this point we know how many file systems there are, so we can reserve some space.
  results.filesystems.reserve(lines.size() - 1);

  std::vector<std::string> columns;
  columns.reserve((unsigned long) this->column_count);

  auto line_it = lines.begin() + 1;

  std::uint64_t filesystem_size, filesystem_used, filesystem_available, total_filesystem_size;
  filesystem_size = filesystem_used = filesystem_available = total_filesystem_size = 0;

  std::string line;
  for (line_it; line_it != lines.end(); ++line_it) {
    line = *line_it;

    if (line.length() == 0) {
        continue;
    }

    boost::split(columns, line, boost::is_any_of(" "), boost::token_compress_on);

    if (columns.size() != this->column_count) {
        std::cerr << "Invalid command output "<< line << "\n";
        break;
    }

    filesystem_size = (std::uint64_t) strtol(columns.at(1).c_str(), nullptr, 10);
    filesystem_used = (std::uint64_t) strtol(columns.at(2).c_str(), nullptr, 10);
    filesystem_available = (std::uint64_t) strtol(columns.at(3).c_str(), nullptr, 10);
    total_filesystem_size += filesystem_size;

    results.filesystems.push_back(Core::Sys::FileSystem(
        columns.at(0),
        filesystem_size,
        filesystem_used,
        filesystem_available
    ));
  }

  Core::Sys::FileSystem::SetTotalFileSystemSize(total_filesystem_size);
}

}
}
