#ifndef CORE_PROCESS_H
#define CORE_PROCESS_H

namespace SystemMonitor
{
namespace Core
{
class Process
{
    public:

        /**
         * @brief Representation of proc/PID/statm columns
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
         * @brief Get the "actual" memory usage of a process.
         *
         * @return
         */
        double GetActualMemoryUsage() const;

        /**
         * @brief Get the relative memory usage of a process.
         *
         * @return
         */
        double GetRelativeMemoryUsage() const;

        std::string GetExecutable() const;

        bool Kill();

        friend std::ostream &operator<<(std::ostream &stream, const Process &process);
    private:
        /*
         |--------------------------------------------------
         | Static mappings to linux /proc/PID directories.
         |--------------------------------------------------
        */
        static const std::string PD_STATM, PD_CMDLINE;

        // Linux process ID
        uint32_t pid;

        // Base path to process /proc/this->pid
        std::string process_base_path;

        // Executable name
        std::string executable;

        // Path to executable
        std::string path;

        // Memory usage of this process.
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
} // End Core
} // End SystemMonitor

#endif //SYSTEM_MONITOR_PROCESS_H
