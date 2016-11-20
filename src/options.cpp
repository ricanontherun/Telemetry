#include <options.h>
#include <unordered_map>
#include <iostream>

namespace LixProc
{

void parse_options(int argc, char **argv, struct options *options)
{
  switch (argc) {
    case 1: // Gather all resources and print to stdout.
      break;
    case 2: // Depends.
    {
      const char *flag = argv[1];
      if ( flag[0] == '-' ) { // Parse as flag
        parse_resource_flags(flag, options);
      } else {
        options->output_path = std::string(flag);
      }
    }
      break;
    default:
      // Parse the flags.
      options->output_path = std::string(argv[2]);
      break;
  }
}

static void parse_resource_flags(const char *flag, struct options *options)
{
  std::unordered_map<char, Resource> resource_map = {
      {'p', Resource::PROCESSES}
  };

  for ( int i = 1; flag[i] != '\0'; i++ ) {
    if ( auto resource = resource_map.find(flag[i]) != resource_map.end() ) {
      options->resources |= resource;
    }
  }
}

}