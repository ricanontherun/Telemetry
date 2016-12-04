#ifndef LIXPROC_READABLE_H
#define LIXPROC_READABLE_H

namespace LixProc {
namespace Interfaces {

class Readable {
 public:
  virtual void Read() = 0;
};

}
}

#endif //LIXPROC_READABLE_H
