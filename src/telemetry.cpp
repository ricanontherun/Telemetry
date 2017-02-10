#include <telemetry.h>

#include <Collectors/ProcessCollector.h>
#include <Collectors/DiskCollector.h>

namespace Telemetry {

Unit::Unit() : options(Options()) {}

Unit::Unit(Options options) : options(options) {}

void Unit::Read(Telemetry::Results & results) {
  this->QuerySystem(results);
}

void Unit::QuerySystem(Telemetry::Results & results) {
  if (this->ResourceFlagSet(Resource::PROCESSES)) {
    Collectors::ProcessCollector collector;
    collector.collect(results);
  }

  if (this->ResourceFlagSet(Resource::FILESYSTEMS)) {
    Collectors::DiskCollector disk_collector;
    disk_collector.collect(results);
  }
}

inline bool Unit::ResourceFlagSet(Resource flag) {
  return (this->options.resources & (Resource::ALL | flag)) != 0;
}

}
