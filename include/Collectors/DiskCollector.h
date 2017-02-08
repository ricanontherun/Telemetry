#ifndef TELEMETRY_COLLECTOR_DISK_H
#define TELEMETRY_COLLECTOR_DISK_H

#include <interfaces/Collector.h>

namespace Telemetry {
namespace Collectors {

class DiskCollector : public Interfaces::Collector {
 public:
  virtual void collect(Results & results);
 private:
  const short column_count = 4;
  const char *command_string = "df --output=source,size,used,avail";
};

}
}

#endif
