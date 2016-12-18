#include <telemetry.h>

#include <Collectors/ProcessCollector.h>
#include <Collectors/SystemCollector.h>

namespace Telemetry {

Unit::Unit(int flags) : flags(flags) {}

void Unit::Read() {
  nlohmann::json j = nlohmann::json::object();

  this->QuerySystem(j);

  std::cout << j << "\n";
}

void Unit::Read(std::string &output) {
  nlohmann::json j = nlohmann::json::object();

  this->QuerySystem(j);

  output = j.dump();
}

void Unit::QuerySystem(nlohmann::json &json) {
  if (this->flags & Resource::PROCESSES) {
    Collectors::ProcessCollector collector;
    collector.load();
    collector.toJSON(json);
  }

  if (this->flags & Resource::SYSTEM) {
    Collectors::SystemCollector system_collector;
    system_collector.load();
    system_collector.toJSON(json);
  }
}

}