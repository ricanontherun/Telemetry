#include <Collectors/DiskCollector.h>

namespace Telemetry {
namespace Collectors {

DiskCollector::DiskCollector() : disk(Core::Sys::Disk()) {}

void DiskCollector::load() {
  this->disk.Read();
}

void DiskCollector::toJSON(nlohmann::json &json) const {
  Core::Sys::FileSystemIterators iterators = this->disk.GetFileSystemIterators();

  using json_t = nlohmann::json;

  json["disks"] = {};

  for (auto it = iterators.first; it != iterators.second; it++) {
    json_t object = json_t::object();


    object["filesystem"] = it->GetSource();
    object["size"] = it->GetSize();
    object["used"] = it->GetUsed();
    object["available"] = it->GetAvailable();

    json["disks"].push_back(object);
  }
}

}
}