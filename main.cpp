#include <iostream>

#include "manager/ProcessManager.h"

int main()
{
    SystemMonitor::ProcessManager *manager = new SystemMonitor::ProcessManager;
    manager->Load();
    delete manager;
    return 0;
}
