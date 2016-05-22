#include "Manager.h"
#include "ProcessManager.h"

std::map<Manager::MANAGER_TYPE, Manager *> Manager::instances;

/**
* @brief Returns a singleton instance of a specified manager.
*
* @param type
*
* @return
*/
Manager *Manager::Instance(MANAGER_TYPE type)
{
    // First, check if this type instance exists in the map.
    std::map<MANAGER_TYPE, Manager *>::iterator it = Manager::instances.find(type);

    if (it != Manager::instances.end())
    {
        return it->second;
    }

    Manager *api;

    // Create the new type.
    switch (type)
    {
        case Manager::MANAGER_TYPE::PROCESS:
            api = new ProcessManager();
        case Manager::MANAGER_TYPE::NETWORK:
            break;
    }

    // Store it in the map.
    Manager::instances[type] = api;

    return api;
}
