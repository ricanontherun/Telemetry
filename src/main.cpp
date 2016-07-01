#include <regex>
#include <string>
#include <iostream>

#include <core/sys/SystemInfo.h>
#include <manager/ProcessManager.h>

int main(int argc, char **argv)
{
    LixProc::SystemInfo::Capture();

    using LixProc::Manager::ProcessIterators;
    ProcessIterators iterators = LixProc::Manager::ProcessManager::Load();

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}
