#include <iostream>

#include "API.h"
#include "ProcessAPI.h"

using namespace std;

// Initialize the static member.
map<API::API_TYPES, API *> API::instances;

API *API::Create(API_TYPES type)
{
    // First, check if this type instance exists in the map.
    map<API_TYPES, API *>::iterator it = API::instances.find(type);

    if (it != API::instances.end())
    {
        // Is this REALLY how you access the value in a map iterator?
        return it->second;
    }

    API *api;

    // Create the new type.
    switch (type)
    {
        case API::API_TYPES::PROCESS:
            api = new ProcessAPI();
        case API::API_TYPES::NETWORK:
            break;
    }

    // Store it in the map.
    API::instances[type] = api;

    return api;
}