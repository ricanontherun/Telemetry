#include <Collectors/DiskCollector.h>
#include <results.h>

namespace Telemetry {
namespace Collectors {

DiskCollector::DiskCollector(Results * results)
    : disk(Core::Sys::Disk()), Collector(results) {}

void DiskCollector::load() {
  this->disk.Read();

  Core::Sys::FileSystemIterators iterators = this->disk.GetFileSystemIterators();

  // Store the filesystems we've just gathered in the results object.
  this->results->filesystems.assign(iterators.first, iterators.second);
}

}
}
