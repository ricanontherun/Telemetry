#include <utils/shell.h>

#include <algorithm>
#include <iostream>

namespace LixProc {

bool RunInShell(const char *command, std::string &out) {
  FILE *fp = popen(command, "r");

  if (!fp) { return false; }

  char buf[BUFSIZ];

  while (fgets(buf, BUFSIZ, fp)) {
    out += std::string(buf); // We're modifying their string argument in loop.
  }

  return pclose(fp) != -1;
}

}