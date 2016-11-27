#ifndef LIXPROC_SYSTEMCOLLECTOR_H
#define LIXPROC_SYSTEMCOLLECTOR_H

#include <Collectors/Collector.h>

namespace LixProc {
namespace Collectors {

class SystemCollector : public Collector {
 public:
  void toJSON(nlohmann::json &json) const;
  void load();
};

}
}

#endif //LIXPROC_SYSTEMCOLLECTOR_H
