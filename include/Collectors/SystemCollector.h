#ifndef LIXPROC_SYSTEMCOLLECTOR_H
#define LIXPROC_SYSTEMCOLLECTOR_H

#include <interfaces/Collector.h>

namespace LixProc {
namespace Collectors {

class SystemCollector : public Interfaces::Collector {
 public:
  void toJSON(nlohmann::json &json) const;
  void load();
};

}
}

#endif //LIXPROC_SYSTEMCOLLECTOR_H
