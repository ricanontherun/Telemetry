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
#include <core/process/Process.h>

#include <utils/str.h>
#include <utils/file.h>
#include <core/sys/SystemInfo.h>

#include <fstream>
#include <cmath>
#include <iostream>

namespace Telemetry
{
namespace Core
{

const std::string Process::PD_STATM   = "statm";
const std::string Process::PD_CMDLINE = "cmdline";
const std::string Process::PD_BASE = "/proc/";

/**
* @brief Load all of the data associated with /proc/pid
*
* @param pid
*/
Process::Process(uint32_t pid) : pid(pid), base_path(Process::PD_BASE + std::to_string(pid))
{
    this->LoadProcessData();
}

Process::~Process()
{
}

/**
 * @brief Get the "actual" memory usage of a process.
 *
 * @return
 */
double Process::GetActualMemoryUsage() const
{
    uint64_t resident = this->memory.resident;

    double actual = static_cast<double>(resident * SystemInfo::GetPageSize());

    return actual;
}

/**
 * @brief Get the relative memory usage of a process.
 *
 * @return
 */
double Process::GetRelativeMemoryUsage() const
{
    double process_memory_bytes = this->GetActualMemoryUsage();

    unsigned long system_memory_bytes = SystemInfo::GetTotalSystemMemory();

    return round((process_memory_bytes / system_memory_bytes) * 100.00);
}

uint32_t Process::GetPID() const
{
  return this->pid;
}

// TODO: are we sure this is needed feature? The ability to kill a running process...
bool Process::Kill()
{
  return true;
}

/*
|--------------------------------------------------
| Operator Overloads
|--------------------------------------------------
*/
std::ostream &operator<<(std::ostream &stream, const Process &process)
{
    double relative_memory_usage = process.GetRelativeMemoryUsage();
    stream << std::setw(10) << process.GetPID();
    stream << std::setw(10) << std::fixed << std::setprecision(2) << process.GetActualMemoryUsage();
    stream << std::setw(10) << std::fixed << std::setprecision(1) <<  relative_memory_usage;
    stream << process.command() << " ";

    return stream;
}

/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

void Process::LoadProcessData()
{
    using Telemetry::Utils::File::FileExists;

    if (!FileExists(this->base_path)) {
        throw std::runtime_error(this->base_path + std::string(" does not exist."));
    }

    this->LoadProcessCommand();

    this->LoadProcessMemory();
}

bool Process::LoadProcessCommand()
{
    using Telemetry::Utils::File::FileGetFirstLine;

    std::string proc_command = this->base_path + "/" + Process::PD_CMDLINE;

    std::string cmd_string = FileGetFirstLine(proc_command);

    Telemetry::Utils::ParseCommandString(cmd_string, this->command);

    return true;
}

Telemetry::Utils::Command Process::GetCommand() const
{
    return this->command;
}

bool Process::LoadProcessMemory()
{
    using Telemetry::Utils::File::FileGetFirstLine;

    // /proc/PID/statm
    std::string dir = this->base_path + "/" + Process::PD_STATM;

    // Get the first line is sufficient for a /proc/PID/statm read.
    std::string statm = FileGetFirstLine(dir);

    std::stringstream memory_stream(statm);

    // Yes, this seems much cleaner than split()ing into a vector and atoi()ing the resulting indexes,
    // but is this the best practice? Is there a best practice for this?
    memory_stream >> this->memory.size;
    memory_stream >> this->memory.resident;
    memory_stream >> this->memory.share;
    memory_stream >> this->memory.text;
    memory_stream >> this->memory.lib;
    memory_stream >> this->memory.data;
    memory_stream >> this->memory.dirty;

    return true;
}

} // End Core
} // End Telemetry
