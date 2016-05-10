#ifndef API_API_H 
#define API_API_H 

#include <map>

class API
{
    public:
        virtual ~API() {}

        // Types of factories
        enum class API_TYPES
        {
            PROCESS, NETWORK
        };

        static API *Instance(API_TYPES type);

    private:
        static std::map<API_TYPES, API *> instances;
};

#endif
