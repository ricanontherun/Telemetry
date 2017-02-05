#include <telemetry.h>

#include <Collectors/ProcessCollector.h>
#include <Collectors/DiskCollector.h>

namespace Telemetry {

Unit::Unit() : options(Options()) {}

Unit::Unit(Options options) : options(options) {}

void Unit::Read(Telemetry::Results * results) {
  this->QuerySystem(results);
}

void Unit::QuerySystem(Telemetry::Results * results) {
  if (this->ResourceFlagSet(Resource::PROCESSES)) {
    Collectors::ProcessCollector collector(results);
    collector.load();
  }

  if (this->ResourceFlagSet(Resource::DISK)) {
    Collectors::DiskCollector disk_collector(results);
    disk_collector.load();
  }
}

inline bool Unit::ResourceFlagSet(Resource flag) {
  return (this->options.resources & (Resource::ALL | flag)) != 0;
}

}
