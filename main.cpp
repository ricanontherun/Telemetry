#include <iostream>

#include "manager/Manager.h"
#include "manager/ProcessManager.h"

int main()
{
    ProcessManager *manager = dynamic_cast<ProcessManager *>(ProcessManager::Instance(ProcessManager::MANAGER_TYPE::PROCESS));

    manager->Load();
    delete manager;
    return 0;
}
