#include <manager/ProcessManager.h>

#include <map>
#include <limits>
#include <errno.h>
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <stdint.h>
#include <unistd.h>
#include <stdexcept>

#include <core/sys/SystemUser.h>
#include <core/sys/SystemInfo.h>
#include <utils/str.h>

namespace LixProc
{
namespace Manager
{

std::string ProcessManager::proc_root = "/proc/";
std::map<uint32_t, std::unique_ptr<Core::Process>> ProcessManager::processes;

/**
 * @brief Load the process list.
 */
ProcessIterators ProcessManager::Load()
{
    ProcessManager::LoadProcessList();

    return ProcessManager::MakeIterators();
}

/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

/**
 * @brief Load the process list.
 */
void ProcessManager::LoadProcessList()
{

    DIR *d;
    struct dirent *de;

    d = opendir(ProcessManager::proc_root.c_str());

    // If we can't read from /proc something is very wrong.
    if (d == NULL)
    {
        closedir(d);
    }

    uint64_t pid = 0;

    while ((de = readdir(d)))
    {
        if (de->d_type != DT_DIR || !(pid = LixProc::Utils::ConvertToInteger(de->d_name)))
        {
            continue;
        }

        try {
            ProcessManager::Load(pid);
        } catch( std::runtime_error &e ) {

        }
    }

    closedir(d);
}

void ProcessManager::Load(uint64_t pid)
{
    struct stat info;
    int stat_i;

    std::string dir_name = std::to_string(pid);
    std::string full_process_path = ProcessManager::proc_root + dir_name;

    stat_i = stat(full_process_path.c_str(), &info);

    if (stat_i == -1)
    {
        // TODO: Determine appropriate action. If the file doesn't exist,
        // that probably shouldn't be an error. Else, write to a log?
        std::cout << strerror(errno) << std::endl;
    }

    // Are we the owner of the process?
    if (SystemUser::GetUserID() != info.st_uid || SystemUser::GetGroupID() != info.st_gid)
    {
        return;
    }

    try {
        ProcessManager::processes[pid] = std::unique_ptr<Core::Process>(new Core::Process(pid));
    } catch( std::runtime_error &error ) {
        std::cerr << error.what() << std::endl;
    }
}

ProcessIterator ProcessManager::Begin() const
{
    return ProcessManager::processes.begin();
}

ProcessIterator ProcessManager::End() const
{
    return ProcessManager::processes.end();
}

ProcessIterators ProcessManager::MakeIterators()
{
    return std::make_pair(ProcessManager::processes.begin(), ProcessManager::processes.end());
}

} // End Manager
} // End LixProc
