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
typedef std::pair<ProcessIterator, ProcessIterator> ProcessIterators;

class ProcessManager
{
    public:
        /**
         * @brief Load all active processes.
         */
        static ProcessIterators Load();

        /**
         * @brief Load a particular process.
         *
         * @param pid
         */
        static void Load(uint64_t pid);

        /**
         * Load all processes whose executables match a particular name.
         *
         * @param name
         */
        void Load(std::string name);

        ProcessIterator Begin() const;
        ProcessIterator End() const;
    private:
        // Base process directory path.
        static std::string proc_root;

        // Map of processes, keyed by their respective PID
        static std::map<uint32_t, std::unique_ptr<Core::Process>> processes;

        /**
         * @brief Load the process list.
         */
        static void LoadProcessList();

        /**
         * @brief Attempt to convert a string into an integer.
         *
         * @param string
         *
         * @return
         */
        // TODO: Pull out into a utilities file. str.h
        static uint64_t GetStringInteger(char *string);

        static ProcessIterators MakeIterators();
};

} // End Manager
} // End LixProc

#endif //PROCESS_API_H
