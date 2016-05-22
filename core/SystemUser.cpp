#include <unistd.h>

#include "SystemUser.h"

uid_t SystemUser::uid = 0;
gid_t SystemUser::gid = 0;

void SystemUser::Capture()
{
    if ( SystemUser::uid == 0 ) {
        SystemUser::uid = getuid();
    }

    if ( SystemUser::gid == 0 ) {
        SystemUser::gid = getgid();
    }
}

uid_t SystemUser::GetUserID()
{
    return SystemUser::uid;
}

gid_t SystemUser::GetGroupID()
{
    return SystemUser::gid;
}
