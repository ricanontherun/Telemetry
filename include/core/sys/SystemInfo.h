#ifndef CORE_SYS_SYSTEMINFO_H
#define CORE_SYS_SYSTEMINFO_H

#include <unistd.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

namespace LixProc
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
        static struct sysinfo sys_info;
        static int pagesize;
        static bool captured;

        static void CaptureSystemStatistics();
        static void CapturePageSize();
};

}

#endif
