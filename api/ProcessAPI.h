#ifndef SYSTEM_MONITOR_PROCESS_API_H
#define SYSTEM_MONITOR_PROCESS_API_H

#include <dirent.h>
#include <stdint.h>
#include <iostream>
#include <map>

#include "../core/process/Process.h"
#include "API.h"

class ProcessAPI : public API
{
    public:
        ProcessAPI();
        ~ProcessAPI();

    private:
        map<uint32_t, Process *> process_list;
        void LoadProcessList();
};

#endif //PROCESS_API_H
