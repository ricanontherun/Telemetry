#include <iostream>

#include "manager/ProcessManager.h"

int main()
{
    SystemMonitor::Manager::ProcessManager *manager = new SystemMonitor::Manager::ProcessManager;
    manager->Load();
    delete manager;
    return 0;
}
