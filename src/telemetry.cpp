#include <telemetry.h>
#include <options.h>

#include <Collectors/ProcessCollector.h>
#include <Collectors/DiskCollector.h>
#include <Collectors/CPUCollector.h>

namespace Telemetry {

Unit::Unit() : options(Options()) {}

Unit::Unit(Options options) : options(options) {}

void Unit::Read(const Options & options,Telemetry::Results & results) {
  this->options = options;

  this->Read(results);
}

void Unit::Read(Telemetry::Results & results) {
  if (this->ResourceFlagSet(Resource::PROCESSES)) {
    Collectors::ProcessCollector collector;
    collector.collect(results);
  }

  if (this->ResourceFlagSet(Resource::FILESYSTEMS)) {
    Collectors::DiskCollector disk_collector;
    disk_collector.collect(results);
  }

  if ( this->ResourceFlagSet(Resource::CPU) ) {
    Collectors::CPUCollector cpu_collector;
    cpu_collector.collect(results);
  }
}

/**
 * @param flag
 *
 * @return
 */
inline bool Unit::ResourceFlagSet(Resource flag) {
  return (this->options.resources & (static_cast<std::uint16_t>(Resource::ALL) | static_cast<std::uint16_t>(flag))) != 0;
}

}
