#include "Process.h"

using namespace std;

Process::Process(uint32_t pid)
{
    this->pid = pid;
    std::string full_process_path = this->GetProcessPath();

    // Read and parse the respective /proc/PID/ directories. Easy right?
}

std::string Process::GetProcessPath()
{
    return "/proc/" + std::to_string(this->pid);
}

