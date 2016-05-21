#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "Process.h"
#include "../util/str.h"
#include "../util/file.h"

const std::string Process::PD_STATM   = "statm";
const std::string Process::PD_CMDLINE = "cmdline";

struct sysinfo Process::system_info;
struct system_memory Process::system_memory;

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

Process::Memory *Process::GetMemoryUsage() const
{
    return this->memory;    
}

void Process::LoadSystemInfo()
{
    // TODO: We need a data structure here.
    // One that can hold the total system ram, system page size and stuff like that.
    // Query the kernel for the machine's sysinfo.
    // We're going to need this when we start converting process
    // memory usage from mem_units into percentages.
    int reti = sysinfo(&Process::system_memory.system_info);

    if ( reti == -1 ) {
        std::cerr << "Failed to query system information" << std::endl;
        exit(EXIT_FAILURE);
    }

    Process::system_memory.page_size = getpagesize();
    Process::system_memory.total_ram_bytes = Process::system_memory.system_info.totalram 
                                             * Process::system_memory.system_info.mem_unit;
}

/*
|--------------------------------------------------
| Operator Overloads
|--------------------------------------------------
*/
std::ostream &operator<<(std::ostream &stream, const Process &process)
{
    double mem_usage_percentage = (process.memory->size * Process::system_memory.page_size);
    stream << process.command;
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

    unsigned long total_ram_bytes = Process::system_info.totalram * Process::system_info.mem_unit;
    std::cout << total_ram_bytes << std::endl;

    return true;
}
