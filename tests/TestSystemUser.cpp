#include <unistd.h>
#include "test_header.h"

#include <core/sys/SystemUser.h>

TEST_CASE("LixProc::SystemUser")
{
    SECTION("GetUserID will equal the current running user's uid")
    {
        uid_t uid = getuid();
        REQUIRE(LixProc::SystemUser::GetUserID() == uid);
    }

    SECTION("GetGroupID will equal the current running user's gid")
    {
        gid_t gid = getgid();
        REQUIRE(LixProc::SystemUser::GetGroupID() == gid);

    }
}

