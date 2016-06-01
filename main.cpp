#include <iostream>
#include <vector>
#include <string>

#include "core/process/Process.h"
#include "core/util/str.h"
#include "manager/ProcessManager.h"

int main()
{
    SystemMonitor::Manager::ProcessManager manager;

    manager.Load();
    return 0;
}
