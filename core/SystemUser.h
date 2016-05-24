#ifndef CORE_SYSTEM_USER_H
#define CORE_SYSTEM_USER_H

class SystemUser {
    public:
        static void Capture();
        static uid_t GetUserID();
        static gid_t GetGroupID();
    private:
        static uid_t uid;
        static gid_t gid;

};

#endif
