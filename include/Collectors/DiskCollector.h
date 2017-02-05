#ifndef TELEMETRY_COLLECTOR_DISK_H
#define TELEMETRY_COLLECTOR_DISK_H

#include <interfaces/Collector.h>
#include <core/sys/disk.h>

namespace Telemetry {
namespace Collectors {

class DiskCollector : public Interfaces::Collector {
 public:
  DiskCollector(Results * results);

  virtual void toJSON(nlohmann::json &json) const;
  virtual void load();

 private:
  Core::Sys::Disk disk;
};

}
}

#endif