#include <core/sys/SystemUser.h>

#include <unistd.h>

namespace LixProc
{

uid_t SystemUser::uid = 0;
gid_t SystemUser::gid = 0;

uid_t SystemUser::GetUserID()
{
    if ( SystemUser::uid == 0 ) {
        SystemUser::uid = getuid();
    }

    return SystemUser::uid;
}

gid_t SystemUser::GetGroupID()
{
    if ( SystemUser::gid == 0 ) {
        SystemUser::gid = getgid();
    }

    return SystemUser::gid;
}

} // End LixProc
