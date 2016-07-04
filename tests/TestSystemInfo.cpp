#include <unistd.h>
#include "test_header.h"

#include <core/sys/SystemInfo.h>

TEST_CASE("LixProc::SystemInfo")
{
    LixProc::SystemInfo::Capture();

    SECTION("GetPageSize() should return the current system's pagesize.")
    {
        REQUIRE(LixProc::SystemInfo::GetPageSize() == getpagesize());
    }

    SECTION("GetTotalSystemMemory should a number greater than zero.")
    {
        REQUIRE(LixProc::SystemInfo::GetTotalSystemMemory() > 0.0);
    }
}

