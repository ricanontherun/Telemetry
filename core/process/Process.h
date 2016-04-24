#ifndef SYSTEM_MONITOR_PROCESS_H
#define SYSTEM_MONITOR_PROCESS_H

#include <iostream>
#include <stdint.h>

class Process
{
    public:
        Process(uint32_t pid);

    private:
        uint32_t pid;
        std::string GetProcessPath();
};

#endif //SYSTEM_MONITOR_PROCESS_H
