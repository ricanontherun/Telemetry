#ifndef SYSTEM_MONITOR_PROCESS_API_H
#define SYSTEM_MONITOR_PROCESS_API_H

#include <dirent.h>
#include <stdint.h>
#include <iostream>
#include <map>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>

#include "../core/process/Process.h"
#include "API.h"

class ProcessAPI : public API
{
    public:
        ProcessAPI();
        ~ProcessAPI();

    private:
        static string proc_root;
        map<uint32_t, Process *> process_list;

        void LoadProcessList();
        uint64_t GetStringInteger(char *string);
};

#endif //PROCESS_API_H
