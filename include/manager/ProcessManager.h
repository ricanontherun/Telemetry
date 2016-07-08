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
        static ProcessIterators Load(const std::string &name);
    private:
        // Base process directory path.
        static std::string proc_root;

        // Map of processes, keyed by their respective PID
        static std::map<uint32_t, std::unique_ptr<Core::Process>> processes;

        /**
         * @brief Load the process list.
         */
        static void LoadProcessList();

        static ProcessIterators MakeIterators();
};

} // End Manager
} // End LixProc

#endif
