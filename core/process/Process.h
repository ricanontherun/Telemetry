#ifndef SYSTEM_MONITOR_PROCESS_H
#define SYSTEM_MONITOR_PROCESS_H

#include <iostream>
#include <stdint.h>

using namespace std;

struct ProcessMemory {
    uint64_t m_program;
    uint64_t m_num_portions;
    uint64_t m_num_shared_pages;
    uint64_t m_num_code_pages;
    uint64_t m_num_stack_pages;
    uint64_t m_num_lib_pages;
    uint64_t m_num_dirty_pages;
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
