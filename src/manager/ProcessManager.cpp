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
#include <algorithm>

#include <utils/str.h>
#include <core/sys/SystemUser.h>
#include <core/sys/SystemInfo.h>

namespace LixProc
{
namespace Manager
{

std::map<uint32_t, std::unique_ptr<Core::Process>> ProcessManager::processes;

/**
 * @brief Load the process list.
 */
ProcessIterators ProcessManager::Load()
{
    ProcessManager::LoadProcessList();

    return ProcessManager::MakeIterators();
}

void ProcessManager::Load(uint64_t pid)
{
    struct stat info;
    int stat_i;

    std::string dir_name = std::to_string(pid);
    std::string full_process_path = Core::Process::PD_BASE + dir_name;

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
        ProcessManager::processes[pid] = std::make_unique<Core::Process>(pid);
    } catch( std::runtime_error &error ) {
        std::cerr << error.what() << std::endl;
    }
}

ProcessIterators ProcessManager::Load(const std::string &name)
{
    // First, load all processes.
    ProcessManager::Load();

    Utils::Command command;

    // Iterate and erase any processes whose executable names don't match the name filter.
    for ( auto it = ProcessManager::processes.begin(); it != ProcessManager::processes.end(); ) {
        command = it->second->GetCommand();

        if ( command.name != name ) {
            it = ProcessManager::processes.erase(it);
        } else {
            it++;
        }
    }

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

    d = opendir(Core::Process::PD_BASE.c_str());

    // If we can't read from /proc something is very wrong.
    if (d == NULL)
    {
        closedir(d);
    }


    while ((de = readdir(d)))
    {
        uint64_t dir_val = 0;
        if (de->d_type != DT_DIR || !(dir_val = LixProc::Utils::ConvertToInteger(de->d_name)))
        {
            continue;
        }

        try {
            ProcessManager::Load(dir_val);
        } catch( std::runtime_error &e ) {

        }
    }

    closedir(d);
}

ProcessIterators ProcessManager::MakeIterators()
{
    return std::make_pair(ProcessManager::processes.begin(), ProcessManager::processes.end());
}

} // End Manager
} // End LixProc
