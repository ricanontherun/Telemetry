#include <core/sys/SystemInfo.h>

namespace LixProc
{

struct sysinfo SystemInfo::sys_info;
int SystemInfo::pagesize = 0;
bool SystemInfo::captured = false;

void SystemInfo::Capture()
{
    if ( SystemInfo::captured == true )
    {
        return;
    }

    SystemInfo::CaptureSystemStatistics();

    SystemInfo::CapturePageSize();

    SystemInfo::captured = true;
}

uint64_t SystemInfo::GetTotalSystemMemory()
{
    return SystemInfo::sys_info.totalram * SystemInfo::sys_info.mem_unit;
}

int SystemInfo::GetPageSize()
{
    return SystemInfo::pagesize;
}

/**
 *--------------------------------------------------
 * Private
 *--------------------------------------------------
 */

void SystemInfo::CaptureSystemStatistics()
{
    int reti = sysinfo(&SystemInfo::sys_info);

    if ( reti == -1 ) {
        std::cerr << "sysinfo call failed. Exiting.." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void SystemInfo::CapturePageSize()
{
    SystemInfo::pagesize = getpagesize();
}

} // End
