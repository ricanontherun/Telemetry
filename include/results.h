#ifndef TELEMETRY_RESULTS_H
#define TELEMETRY_RESULTS_H

#include <core/sys/filesystem.h>
#include <core/process/Process.h>

#include <utility>
#include <vector>

namespace Telemetry {

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
  std::vector<Core::Sys::FileSystem> filesystems;
  std::unordered_map<uint32_t, std::unique_ptr<Core::Process>> processes;

 public:
  Core::Sys::FileSystemIterators GetFilesystemIterators() const {
    return std::make_pair<
        Core::Sys::FileSystemIterator,
        Core::Sys::FileSystemIterator
    >(this->filesystems.begin(), this->filesystems.end());
  }

  Core::ProcessIterators GetProcessIterators() const {
    return std::make_pair<
        Core::ProcessIterator,
        Core::ProcessIterator
    >(this->processes.begin(), this->processes.end());
  };
};

}

#endif