#ifndef LIXPROC_DISK_H
#define LIXPROC_DISK_H

#include <core/sys/filesystem.h>
#include <interfaces/Readable.h>

#include <utility>
#include <vector>

namespace LixProc {
namespace Core {
namespace Sys {

typedef
std::vector<FileSystem>::const_iterator
    FileSystemIterator;

typedef
std::pair<FileSystemIterator, FileSystemIterator>
    FileSystemIterators;

class Disk : public Interfaces::Readable {
 private:
  const short column_count = 4;
  const char *command_string = "df --output=source,size,used,avail";

  std::vector<FileSystem> filesystems;

  void ReadFileSystems();
  void ReadDiskUsage();
 public:
  void Read();

  FileSystemIterators GetFileSystemIterators() const;
};

} // Sys
} // Core
} // Lixproc

#endif //LIXPROC_DISK_H
