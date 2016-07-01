#include <regex>
#include <string>
#include <iostream>

#include <manager/ProcessManager.h>

int main(int argc, char **argv)
{
    using LixProc::Manager::ProcessIterators;
    ProcessIterators iterators = LixProc::Manager::ProcessManager::Load();

    for ( auto it = iterators.first; it != iterators.second; it++ ) {
        std::cout << *(it)->second << std::endl;
    }
}
