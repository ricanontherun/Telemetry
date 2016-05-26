#ifndef MANAGER_PROCESS_H
#define MANAGER_PROCESS_H

#include <map>
#include "../core/process/Process.h"

namespace SystemMonitor
{
    namespace Manager
    {
        class ProcessManager
        {
            public:
                ProcessManager();
                ~ProcessManager();

                /**
                 * @brief Load all active processes.
                 */
                void Load();

                /**
                 * @brief Load a particular process.
                 *
                 * @param pid
                 */
                void Load(uint64_t pid);
            private:
                // Base process directory path.
                static std::string proc_root;

                // Map of processes, keyed by their respective PID
                std::map<uint32_t, Core::Process *> process_list;

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
                uint64_t GetStringInteger(char *string);
        };
    } // End Manager
} // End SystemMonitor

#endif //PROCESS_API_H
