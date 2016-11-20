#ifndef LIXPROC_JSONABLE_H
#define LIXPROC_JSONABLE_H

#include <json.hpp>

namespace LixProc
{

class Jsonable
{
 public:
  virtual void toJSON(nlohmann::json &json) = 0;
};

}

#endif //LIXPROC_JSONABLE_H
