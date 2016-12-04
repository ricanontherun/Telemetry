#include <core/sys/disk.h>

#include <utils/shell.h>

#include <iostream>
#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

namespace LixProc {
namespace Core {
namespace Sys {

void Disk::Read() {
  std::string output;

  if (!RunInShell(this->command_string, output)) {
    return;
  }

  // Split the output in lines.
  std::vector<std::string> lines;
  lines.reserve((std::size_t) std::count(output.begin(), output.end(), '\n'));
  boost::split(lines, output, boost::is_any_of("\n"), boost::token_compress_on);

  this->filesystems.reserve(lines.size() - 1);

  std::vector<std::string> columns;
  columns.reserve((unsigned long) this->column_count);

  // We're skipping the first line, which is the header.
  auto line_it = lines.begin() + 1;

  for (line_it; line_it != lines.end(); ++line_it) {
    boost::split(columns, *line_it, boost::is_any_of(" "), boost::token_compress_on);

    if (columns.size() != this->column_count) {
      // Log an error
      continue;
    }

    this->filesystems.push_back(FileSystem(
        columns.at(0),
        (std::uint64_t) strtol(columns.at(1).c_str(), nullptr, 10),
        (std::uint64_t) strtol(columns.at(2).c_str(), nullptr, 10),
        (std::uint64_t) strtol(columns.at(3).c_str(), nullptr, 10)
    ));
  }
}

FileSystemIterators Disk::GetFileSystemIterators() const {
  return std::make_pair(
      this->filesystems.begin(),
      this->filesystems.end()
  );
}

} // Sys
} // Core
} // Lixproc