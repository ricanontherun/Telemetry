// Copyright (C) 2016 Christian Roman
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef CORE_PROCESS_H
#define CORE_PROCESS_H

#include <utils/command.h>

namespace LixProc
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

        /*
         |--------------------------------------------------
         | Static mappings to linux /proc/PID directories.
         |--------------------------------------------------
        */
        static const std::string PD_STATM, PD_CMDLINE, PD_BASE;

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

        LixProc::Utils::Command GetCommand() const;

        bool Kill();

        friend std::ostream &operator<<(std::ostream &stream, const Process &process);
    private:
        uint32_t pid;

        // Base path to process /proc/this->pid
        std::string base_path;

        // Memory usage of this process.
        struct Memory memory;

        LixProc::Utils::Command command;

        /** * @brief Load the process's data.  *
        * @return
        */
        void LoadProcessData();

        /**
        * @brief Load the process's executable and arguments.
        *
        * @return
        */
        bool LoadProcessCommand();

        /**
        * @brief Load the process's memory usage.
        *
        * @return
        */
        bool LoadProcessMemory();
};
} // End Core
} // End LixProc

#endif //SYSTEM_MONITOR_PROCESS_H
