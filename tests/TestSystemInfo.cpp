#include <unistd.h>
#include "test_header.h"

#include <core/sys/SystemInfo.h>

TEST_CASE("LixProc::SystemInfo")
{
    SECTION("PageSize() should default to 0")
    {
        REQUIRE(LixProc::SystemInfo::GetPageSize() == 0);
    }

    LixProc::SystemInfo::Capture();

    SECTION("PageSize() should return the current system's pagesize.")
    {
        int actual_pagesize = getpagesize();
        REQUIRE(LixProc::SystemInfo::GetPageSize() == actual_pagesize);
    }
}

