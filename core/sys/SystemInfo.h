#ifndef CORE_SYS_SYSTEMINFO_H
#define CORE_SYS_SYSTEMINFO_H

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <iostream>

namespace SystemMonitor
{
    class SystemInfo
    {
        public:
            static void Capture();
            static uint64_t GetTotalSystemMemory();
            static int GetPageSize();
        private:
            static struct sysinfo info;
            static int pagesize;

    };
}

#endif
