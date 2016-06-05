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
        /**
         * Capture information about the host machine.
         */
        static void Capture();

        /**
         * Get the host machine's amount of RAM in bytes.
         */
        static uint64_t GetTotalSystemMemory();

        /**
         * Get the host system's page size.
         */
        static int GetPageSize();
    private:
        static struct sysinfo info;
        static int pagesize;

};

}

#endif
