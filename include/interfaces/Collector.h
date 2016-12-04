#ifndef LIXPROC_COLLECTOR_H
#define LIXPROC_COLLECTOR_H

#include <json.hpp>

namespace LixProc
{
namespace Interfaces {

class Collector
{
 public:
  /**
   *
   * @param json
   */
  virtual void toJSON(nlohmann::json &json) const = 0;

  virtual void load() = 0;
};

}
}

#endif //LIXPROC_COLLECTOR_H
