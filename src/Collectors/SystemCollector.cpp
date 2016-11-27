#include <Collectors/SystemCollector.h>
#include <core/sys/SystemInfo.h>

namespace LixProc {
namespace Collectors {

void SystemCollector::toJSON(nlohmann::json &json) const {
  json["system"] = {
      {"memory", SystemInfo::GetTotalSystemMemory()}
  };

  // cpu
  json["system"]["cpu"] = nlohmann::json::object();
  json["system"]["cpu"]["architecture"] = SystemInfo::GetCPU().architecture;
  json["system"]["cpu"]["model"] = SystemInfo::GetCPU().model_name;
}

void SystemCollector::load() {
  LixProc::SystemInfo::Capture();
}

}
}