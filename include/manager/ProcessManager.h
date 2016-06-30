#ifndef MANAGER_PROCESS_H
#define MANAGER_PROCESS_H

#include <map>
#include <memory>

#include <core/process/Process.h>

namespace LixProc
{
namespace Manager
{

typedef std::map<uint32_t, std::unique_ptr<Core::Process>>::const_iterator ProcessIterator;

class ProcessManager
{
    public:
        ProcessManager();

        /**
         * @brief Load all active processes.
         */
        ProcessIterator Load();

        /**
         * @brief Load a particular process.
         *
         * @param pid
         */
        void Load(uint64_t pid);

        /**
         * Load all processes whose executables match a particular name.
         *
         * @param name
         */
        void Load(std::string name);
    private:
        // Base process directory path.
        static std::string proc_root;

        // Map of processes, keyed by their respective PID
        std::map<uint32_t, std::unique_ptr<Core::Process>> processes;

        /**
         * @brief Load the process list.
         */
        void LoadProcessList();

        /**
         * @brief Attempt to convert a string into an integer.
         *
         * @param string
         *
         * @return
         */
        // TODO: Pull out into a utilities file. str.h
        uint64_t GetStringInteger(char *string);

        ProcessIterator GetProcessIterator() const;
};

} // End Manager
} // End LixProc

#endif //PROCESS_API_H
