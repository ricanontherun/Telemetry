#include "SystemInfo.h"

namespace SystemMonitor
{

struct sysinfo SystemInfo::info;
int SystemInfo::pagesize = 0;

void SystemInfo::Capture()
{
    int reti = sysinfo(&SystemInfo::info);

    if ( reti == -1 ) {
        std::cerr << "sysinfo call failed. Exiting.." << std::endl;
        exit(EXIT_FAILURE);
    }

    SystemInfo::pagesize = getpagesize();
}

uint64_t SystemInfo::GetTotalSystemMemory()
{
    return SystemInfo::info.totalram * SystemInfo::info.mem_unit;
}

int SystemInfo::GetPageSize()
{
    return SystemInfo::pagesize;
}

} // End
