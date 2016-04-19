#ifndef SYSTEM_MONITOR_API_H
#define SYSTEM_MONITOR_API_H

/**
 * Class used to manage API singletons.
 */

#include <map>

using namespace std;

class API
{
    public:
        virtual ~API() {}

        // Types of factories
        enum class API_TYPES
        {
            PROCESS, NETWORK
        };

        static API *Create(API_TYPES type);

    private:
        static map<API_TYPES, API *> instances;
};

#endif
