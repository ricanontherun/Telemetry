#include <unistd.h>
#include "test_header.h"

#include <core/sys/SystemUser.h>

TEST_CASE("LixProc::SystemUser")
{
    SECTION("Test that SystemUser is initialized with gid and uid of 0")
    {
        REQUIRE(LixProc::SystemUser::GetUserID() == 0);
    }

    LixProc::SystemUser::Capture();

    SECTION("After Capture(), GetUserID should not return 0")
    {
        REQUIRE(LixProc::SystemUser::GetUserID() != 0);
    }

    SECTION("After Capture(), GetGroupID should not return 0")
    {
        REQUIRE(LixProc::SystemUser::GetGroupID() != 0);
    }

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

