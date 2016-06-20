#ifndef CORE_SYSTEM_USER_H
#define CORE_SYSTEM_USER_H

namespace LixProc
{

class SystemUser {
    public:
        /**
         * "Capture" the current running user's uid and gid.
         */
        static void Capture();
        static uid_t GetUserID();
        static gid_t GetGroupID();
    private:
        static uid_t uid;
        static gid_t gid;

};

} // End LixProc

#endif
