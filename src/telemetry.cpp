#include <telemetry.h>

#include <Collectors/ProcessCollector.h>
#include <Collectors/SystemCollector.h>
#include <Collectors/DiskCollector.h>

namespace Telemetry {

Unit::Unit() : options(Options()) {}

Unit::Unit(Options options) : options(options) {}

void Unit::Read() {
  nlohmann::json j = nlohmann::json::object();

  this->QuerySystem(j);

  std::cout << j << "\n";
}

void Unit::Read(std::string &output) {
  nlohmann::json j = nlohmann::json::object();

  this->QuerySystem(j);

  output = j.dump(2);
}

void Unit::QuerySystem(nlohmann::json &json) {
  if (this->ResourceFlagSet(Resource::PROCESSES)) {
    Collectors::ProcessCollector collector;
    collector.load();
    collector.setOptions(this->options);
    collector.toJSON(json);
  }

  if (this->ResourceFlagSet(Resource::SYSTEM)) {
    Collectors::SystemCollector system_collector;
    system_collector.load();
    system_collector.toJSON(json);
  }

  if (this->ResourceFlagSet(Resource::DISK)) {
    Collectors::DiskCollector disk_collector;
    disk_collector.load();
    disk_collector.setOptions(this->options); // TODO: Refactor to use a immutable shared reference to this.
    disk_collector.toJSON(json);
  }

}

inline bool Unit::ResourceFlagSet(Resource flag) {
  return (this->options.resources & (Resource::ALL | flag)) != 0;
}

}