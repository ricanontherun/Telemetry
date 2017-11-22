#include <unistd.h>
#include "tests.h"

#include <core/sys/SystemInfo.h>

TEST_CASE("Telemetry::SystemInfo")
{
    Telemetry::SystemInfo::Capture();

    SECTION("GetPageSize() should return the current system's pagesize.")
    {
        REQUIRE(Telemetry::SystemInfo::GetPageSize() == getpagesize());
    }

    SECTION("GetTotalSystemMemory should a number greater than zero.")
    {
        REQUIRE(Telemetry::SystemInfo::GetTotalSystemMemory() > 0.0);
    }
}