#ifndef CORE_PROCESS_H
#define CORE_PROCESS_H

class Process
{
    public:

        /**
        * @brief A light representation of the process's memory usage.
        */
        struct Memory {
            uint64_t size;      // Total Program Size
            uint64_t resident;  // Resident Set Size
            uint64_t share;     // Shared Pages
            uint64_t text;      // code
            uint64_t lib;       // library?
            uint64_t data;      // data/stack
            uint64_t dirty;     // dirty pages
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
         * @brief Get the "actual" memory usage of a process.
         *
         * @return
         */
        double GetActualMemoryUsage() const;

        double GetRelativeMemoryUsage() const;

        friend std::ostream &operator<<(std::ostream &stream, const Process &process);
    private:
        /*
         |--------------------------------------------------
         | Static mappings to linux /proc/PID directories.
         |--------------------------------------------------
        */
        static const std::string PD_STATM, PD_CMDLINE;
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
