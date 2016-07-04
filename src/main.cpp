#include <regex>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>

#include <core/sys/SystemInfo.h>
#include <manager/ProcessManager.h>

int main(int argc, char **argv)
{
    LixProc::SystemInfo::Capture();

    using LixProc::Manager::ProcessIterators;
    using LixProc::Manager::ProcessManager;

    std::string search = "tmux";
    ProcessIterators iterators = ProcessManager::Load(search);

    std::cout << std::distance(iterators.first, iterators.second) << " processes were found" << std::endl;

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}
