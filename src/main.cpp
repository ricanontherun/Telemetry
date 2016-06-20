#include <iostream>
#include <string>
#include <vector>

#include <cli/CommandLoop.h>
#include <manager/ProcessManager.h>

int main()
{
    LixProc::Manager::ProcessManager manager;
    manager.Load();
}
