#include <unistd.h>
#include "test_header.h"

#include "../core/sys/SystemInfo.h"

TEST_CASE("SystemMonitor::SystemInfo")
{
    SECTION("PageSize() should default to 0")
    {
        REQUIRE(SystemMonitor::SystemInfo::GetPageSize() == 0);
    }

    SystemMonitor::SystemInfo::Capture();

    SECTION("PageSize() should return the current system's pagesize.")
    {
        int actual_pagesize = getpagesize();
        REQUIRE(SystemMonitor::SystemInfo::GetPageSize() == actual_pagesize);
    }
}

