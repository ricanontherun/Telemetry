#ifndef CORE_PROCESS_H
#define CORE_PROCESS_H

#include <iostream>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

class Process
{
    public:

        /**
        * @brief A light representation of the process's memory usage.
        */
        struct Memory {
            uint64_t size;
            uint64_t resident;
            uint64_t share;
            uint64_t text;
            uint64_t lib;
            uint64_t data;
            uint64_t dirty;
        };

        /**
        * @brief Load all of the data associated with /proc/pid
        *
        * @param pid
        */
        Process(uint32_t pid);

        ~Process();

        /**
        * @brief Refresh the process data.
        *
        * @return true if all goes well, false if the process has been terminated.
        */
        bool Refresh();

        /**
        * @brief Get the memory usage of the process since last load.
        *
        * @return 
        */
        Process::Memory *GetMemoryUsage() const;

        /**
        * @brief Load the local machine's system stats.
        */
        static void LoadSystemInfo();
    private:
        /*
         |--------------------------------------------------
         | Static mappings to linux /proc/PID directories.
         |--------------------------------------------------
        */
        static const std::string PD_STATM, PD_CMDLINE;

        static struct sysinfo system_info;

        uint32_t pid;
        std::string process_base_path;

        std::string command;
        struct Memory *memory;

        /**
        * @brief Load the process's data.
        *
        * @return 
        */
        bool LoadProcessData();

        /**
        * @brief Load the process's executable and arguments.
        *
        * @return 
        */
        bool LoadProcessName();

        /**
        * @brief Load the process's memory usage.
        *
        * @return 
        */
        bool LoadProcessMemory();
};

#endif //SYSTEM_MONITOR_PROCESS_H
