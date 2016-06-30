#include <regex>
#include <string>
#include <iostream>

#include <manager/ProcessManager.h>

int main(int argc, char **argv)
{
    LixProc::Manager::ProcessManager manager;

    LixProc::Manager::ProcessIterator iterator = manager.Load();
}
