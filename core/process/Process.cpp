#include <iostream>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "Process.h"
#include "../sys/SystemInfo.h"
#include "../util/str.h"
#include "../util/file.h"

const std::string Process::PD_STATM   = "statm";
const std::string Process::PD_CMDLINE = "cmdline";

Process::Process(uint32_t pid)
{

    this->pid = pid;
    this->process_base_path = "/proc/" + std::to_string(this->pid);

    this->LoadProcessData();
}

Process::~Process()
{
    delete this->memory;
}

double Process::GetActualMemoryUsage() const
{
    // What constitutes as a process's memory footprint?
    return this->memory->resident;
}

double Process::GetRelativeMemoryUsage() const
{
    double process_memory_bytes = static_cast<double>(this->GetActualMemoryUsage() * SystemInfo::GetPageSize());

    unsigned long system_memory_bytes = SystemInfo::GetTotalSystemMemory();

    return (process_memory_bytes / system_memory_bytes) * 100.00;
}

/*
|--------------------------------------------------
| Operator Overloads
|--------------------------------------------------
*/
std::ostream &operator<<(std::ostream &stream, const Process &process)
{
    double relative_memory_usage = process.GetRelativeMemoryUsage();
    stream << process.pid << ":" << process.command << " " << relative_memory_usage;
}

/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

bool Process::LoadProcessData()
{
    // TODO: Check that the process actually exists before doing any of this.
    this->LoadProcessName();

    this->LoadProcessMemory();

}

bool Process::LoadProcessName()
{
    std::string dir = this->process_base_path + "/" + Process::PD_CMDLINE;
    char buf[BUFSIZ];

    const char *mode = "r";
    FILE *fp = GetFile(dir.c_str(), mode);

    if ( fp == NULL ) {
        return false;
    }


    if ( fgets(buf, BUFSIZ, fp) == NULL ) {
        fclose(fp);
        return false;
    }

    this->command = buf;

    fclose(fp);
    return true;
}

bool Process::LoadProcessMemory()
{
    this->memory = new Process::Memory;

    // TODO: Can we somehow encapsulate this logic?
    // It is used in both LoadProcessMemory AND LoadProcessName...
    std::string dir = this->process_base_path + "/" + Process::PD_STATM;

    char buf[BUFSIZ];
    FILE *fp = GetFile(dir.c_str(), "r");

    if ( fp == NULL ) {
        return false;
    }

    if ( fgets(buf, BUFSIZ, fp) == NULL ) {
        fclose(fp);
        return false;
    }

    size_t len = strlen(buf);
    if ( buf[len - 1] == '\n' ) {
        buf[len - 1] = '\0';
    }

    fclose(fp);

    // Split the string of memory data.
    std::string memory_string(buf);
    std::vector<std::string> memory_vector = split(memory_string, ' ');

    this->memory->size      = atoi(memory_vector[0].c_str());
    this->memory->resident  = atoi(memory_vector[1].c_str());
    this->memory->share     = atoi(memory_vector[2].c_str());
    this->memory->text      = atoi(memory_vector[3].c_str());
    this->memory->lib       = atoi(memory_vector[4].c_str());
    this->memory->data      = atoi(memory_vector[5].c_str());
    this->memory->dirty     = atoi(memory_vector[6].c_str());

    return true;
}
