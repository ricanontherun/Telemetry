#ifndef TELEMETRY_RESULTS_H
#define TELEMETRY_RESULTS_H

#include <core/sys/filesystem.h>
#include <core/process/Process.h>

#include <utility>
#include <vector>

namespace Telemetry
{

// Forward declare the friend collectors so they can write
// to the Results *'s private members.
namespace Collectors {
class DiskCollector;
class ProcessCollector;
}

// This class should contain const references to
// structures gathering during a Read() operation.
class Results {
  friend class Collectors::DiskCollector;
  friend class Collectors::ProcessCollector;
 private:
  std::vector<Telemetry::Core::Sys::FileSystem> filesystems;
  Core::ProcessIterators process_iterators;

 public:
  // TODO: Define a FileSystemIterators typedef to make this easier.
  std::pair<
    std::vector<Telemetry::Core::Sys::FileSystem>::const_iterator,
    std::vector<Telemetry::Core::Sys::FileSystem>::const_iterator
  >
  GetFilesystemIterators() const {
    return std::make_pair<
        std::vector<Telemetry::Core::Sys::FileSystem>::const_iterator,
        std::vector<Telemetry::Core::Sys::FileSystem>::const_iterator
    >
        (this->filesystems.begin(), this->filesystems.end());
  }

  const Core::ProcessIterators & GetProcessIterators() const {
    return this->process_iterators;
  };
};

}

#endif