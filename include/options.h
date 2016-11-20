#ifndef LIXPROC_OPTIONS_H
#define LIXPROC_OPTIONS_H

#include <string>

namespace LixProc
{

enum class Resource : int
{
  ALL = 0,  // All supported resources will be collected.
  PROCESSES // System processes will be collected.
};

struct options
{
  options() : output_path(""), resources(static_cast<int>(Resource::ALL)) {};

  std::string output_path;
  int resources;
};

void parse_options(int argc, char **argv, struct options *options);
static void parse_resource_flags(const char *flag, struct options *options);

}

#endif //LIXPROC_OPTIONS_H
