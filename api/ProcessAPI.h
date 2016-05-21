#ifndef API_PROCESS_H
#define API_PROCESS_H

#include <dirent.h>
#include <stdint.h>
#include <map>

#include <unistd.h>

#include "../core/process/Process.h"
#include "API.h"

class ProcessAPI : public API
{
    public:
        ProcessAPI();
        ~ProcessAPI();

    private:
        static std::string proc_root;

        std::map<uint32_t, Process *> process_list;

        void LoadProcessList();
        uint64_t GetStringInteger(char *string);
};

#endif //PROCESS_API_H
