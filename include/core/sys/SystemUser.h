#ifndef CORE_SYSTEM_USER_H
#define CORE_SYSTEM_USER_H

#include <sys/types.h>

namespace LixProc
{

class SystemUser {
    public:
        static uid_t GetUserID();
        static gid_t GetGroupID();
    private:
        static uid_t uid;
        static gid_t gid;

};

} // End LixProc

#endif
