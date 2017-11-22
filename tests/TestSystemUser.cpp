#include <unistd.h>
#include "tests.h"

#include <core/sys/SystemUser.h>

TEST_CASE("Telemetry::SystemUser")
{
    SECTION("GetUserID will equal the current running user's uid")
    {
        uid_t uid = getuid();
        REQUIRE(Telemetry::SystemUser::GetUserID() == uid);
    }

    SECTION("GetGroupID will equal the current running user's gid")
    {
        gid_t gid = getgid();
        REQUIRE(Telemetry::SystemUser::GetGroupID() == gid);

    }
}

