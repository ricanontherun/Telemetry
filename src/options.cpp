#include <options.h>
#include <unordered_map>
#include <iostream>

namespace LixProc
{

void parse_options(int argc, char **argv, struct options *options)
{
  for (int i = 1; i < argc; i++) {
    const char *option = argv[i];
    if (option[0] == '-') {
      parse_resource_flags(option, options);
    } else {
      options->output_path = std::string(option);
    }
  }
}

static void parse_resource_flags(const char *flag, struct options *options)
{
  std::unordered_map<char, Resource> resource_map = {
      {'s', Resource::SYSTEM},
      {'p', Resource::PROCESSES}
  };

  for ( int i = 1; flag[i] != '\0'; i++ ) {
    auto resource = resource_map.find(flag[i]);

    if (resource != resource_map.end()) {
      options->resources |= static_cast<int>(resource->second);
    }
  }
}

}