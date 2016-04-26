#ifndef CORE_PROCESS_H
#define CORE_PROCESS_H

#include <iostream>
#include <stdint.h>

using namespace std;

struct ProcessMemory {
    uint64_t size;
    uint64_t resident;
    uint64_t share;
    uint64_t text;
    uint64_t lib;
    uint64_t data;
    uint64_t dirty;
};

class Process
{
    public:
        Process(uint32_t pid);
        ~Process();

        bool Refresh();

    private:
        /*
         |--------------------------------------------------
         | Static mappings to linux /proc/PID directories.
         |--------------------------------------------------
        */
        static const string PD_STATM, PD_CMDLINE;

        uint32_t pid;
        string process_base_path;

        string command;
        struct ProcessMemory *memory;

        bool LoadProcessData();
        bool LoadProcessName();
        bool LoadProcessMemory();
};

#endif //SYSTEM_MONITOR_PROCESS_H
