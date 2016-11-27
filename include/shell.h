#ifndef LIXPROC_SHELL_H
#define LIXPROC_SHELL_H

#include <string>

namespace LixProc {

/**
 * Run a shell command and return it's output via out.
 *
 * @param command
 * @param out
 * @return success
 */
bool RunInShell(const char *command, std::string &out);

}

#endif //LIXPROC_SHELL_H
