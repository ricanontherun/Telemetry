#ifndef API_H
#define API_H
/**
 * Class used to manage different API singletons.
 */

#include <map>

using namespace std;

class API {
    public:
        // Types of factories
        enum class API_TYPES {
            PROCESS, NETWORK
        };

        static API *Create(API_TYPES type);
    private:
        static map<API_TYPES, API*> instances;
};

#endif
