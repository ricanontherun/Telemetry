#ifndef API_PROCESS_H
#define API_PROCESS_H

#include <dirent.h>
#include <stdint.h>
#include <map>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

#include "../core/process/Process.h"
#include "API.h"

class ProcessAPI : public API
{
    public:
        ProcessAPI();
        ~ProcessAPI();

    private:
        static std::string proc_root;

        struct sysinfo system_memory;

        std::map<uint32_t, Process *> process_list;

        void LoadProcessList();
        uint64_t GetStringInteger(char *string);
};

#endif //PROCESS_API_H
