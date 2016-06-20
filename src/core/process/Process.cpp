#include <iostream>
#include <fstream>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdexcept>

#include <core/process/Process.h>
#include <core/sys/SystemInfo.h>

#include <utils/str.h>
#include <utils/file.h>
#include <utils/command.h>

namespace SystemMonitor
{
namespace Core
{

const std::string Process::PD_STATM   = "statm";
const std::string Process::PD_CMDLINE = "cmdline";

/**
* @brief Load all of the data associated with /proc/pid
*
* @param pid
*/
Process::Process(uint32_t pid)
{

    this->pid = pid;
    this->process_base_path = "/proc/" + std::to_string(this->pid);

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
    // What constitutes as a process's memory footprint?
    return this->memory.resident;
}

/**
 * @brief Get the relative memory usage of a process.
 *
 * @return
 */
double Process::GetRelativeMemoryUsage() const
{
    double process_memory_bytes = static_cast<double>(this->GetActualMemoryUsage() * SystemInfo::GetPageSize());

    unsigned long system_memory_bytes = SystemInfo::GetTotalSystemMemory();

    return (process_memory_bytes / system_memory_bytes) * 100.00;
}

bool Process::Kill()
{
    // Acquire permissions to change the process's group.

    // Change the process's group.
    int ret_i = setpgid(this->pid, 0);

    std::cout << "setpdid() is " << ret_i << std::endl;

    // Send a SIGKILL signal to this->pid.
    //
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
    stream << ">>PROCESS ";
    stream << process.pid << std::endl;
    stream << "Exe: " << process.command.name << std::endl;
    stream << "Path: " << process.command.path << std::endl;
    stream << "Args: " << process.command.arguments << std::endl;
    stream << relative_memory_usage << " " << std::endl;

    return stream;
}

/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

void Process::LoadProcessData()
{
    using SystemMonitor::Utils::File::FileExists;

    if (!FileExists(this->process_base_path)) {
        throw std::runtime_error(this->process_base_path + std::string(" does not exist."));
    }

    this->LoadProcessCommand();

    this->LoadProcessMemory();
}

bool Process::LoadProcessCommand()
{
    using SystemMonitor::Utils::File::FileGetFirstLine;

    std::string proc_command = this->process_base_path + "/" + Process::PD_CMDLINE;
    std::string cmd_string = FileGetFirstLine(proc_command);

    SystemMonitor::Utils::ParseCommandString(cmd_string, this->command);

    return true;
}

SystemMonitor::Utils::Command Process::GetCommand() const
{
    return this->command;
}

bool Process::LoadProcessMemory()
{
    using SystemMonitor::Utils::File::FileGetFirstLine;
    std::string dir = this->process_base_path + "/" + Process::PD_STATM;

    std::string memory_string = FileGetFirstLine(dir);

    // Split the statm file on spaces, and place each memory chunk in the vector.
    // There must be a better way to do this, possible stringstreams?
    std::vector<std::string> memory_vector = Utils::split(memory_string, ' ');
    this->memory.size      = atoi(memory_vector[0].c_str());
    this->memory.resident  = atoi(memory_vector[1].c_str());
    this->memory.share     = atoi(memory_vector[2].c_str());
    this->memory.text      = atoi(memory_vector[3].c_str());
    this->memory.lib       = atoi(memory_vector[4].c_str());
    this->memory.data      = atoi(memory_vector[5].c_str());
    this->memory.dirty     = atoi(memory_vector[6].c_str());

    return true;
}

} // End Core
} // End SystemMonitor
