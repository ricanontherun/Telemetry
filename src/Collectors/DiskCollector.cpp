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

void DiskCollector::toJSON(nlohmann::json &json) const {
  Core::Sys::FileSystemIterators iterators = this->disk.GetFileSystemIterators();

  using json_t = nlohmann::json;

  json["filesystems"] = {};

  for (auto it = iterators.first; it != iterators.second; it++) {
    json_t object = json_t::object();

    object["label"] = it->GetSource();
    object["size"] = it->GetSize();
    object["used"] = it->GetUsed();
    object["available"] = it->GetAvailable();
    object["relative_used"] = it->GetPercentUsed();

    json["filesystems"].push_back(object);
  }
}

}
}