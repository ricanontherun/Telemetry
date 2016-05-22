#ifndef MANAGER_H
#define MANAGER_H

#include <map>

class Manager
{
    public:
        virtual ~Manager() {}

        // Manager types.
        enum class MANAGER_TYPE
        {
            PROCESS, NETWORK
        };

        /**
        * @brief Returns a singleton instance of a specified manager.
        *
        * @param type
        *
        * @return
        */
        static Manager *Instance(MANAGER_TYPE type);

    private:
        // Instance map
        static std::map<MANAGER_TYPE, Manager *> instances;
};

#endif
