#ifndef LIXPROC_FILESYSTEM_H
#define LIXPROC_FILESYSTEM_H

#include <cstdint>
#include <string>

namespace LixProc {
namespace Core {
namespace Sys {

class FileSystem {
 private:
  std::string source;
  std::uint64_t size;
  std::uint64_t used;
  std::uint64_t avail;

 public:
  FileSystem() : source(""), size(0), used(0), avail(0) {};
  FileSystem(std::string source, std::uint64_t size, std::uint64_t used, std::uint64_t avail)
      : source(source), size(size), used(used), avail(avail) {};

  const std::string &GetSource() const {
    return this->source;
  };

  const std::uint64_t &GetSize() const {
    return this->size;
  }

  const std::uint64_t &GetUsed() const {
    return this->used;
  };

  const std::uint64_t &GetAvailable() const {
    return this->avail;
  };
};

}
}
}

#endif //LIXPROC_FILESYSTEM_H
