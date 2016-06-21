#include <stdexcept>
#include <iostream>
#include <limits>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <stdint.h>
#include <map>
#include <unistd.h>

#include <manager/ProcessManager.h>
#include <core/sys/SystemUser.h>
#include <core/sys/SystemInfo.h>

namespace LixProc
{
namespace Manager
{

std::string ProcessManager::proc_root = "/proc/";

ProcessManager::ProcessManager()
{
    // Capture some static data needed.
    LixProc::SystemUser::Capture();
    LixProc::SystemInfo::Capture();
}

/**
 * @brief Load the process list.
 */
void ProcessManager::Load()
{
    this->LoadProcessList();
}

/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

/**
 * @brief Attempt to convert a string into an integer.
 *
 * @param string
 *
 * @return
 */
uint64_t ProcessManager::GetStringInteger(char *string)
{
    char *end;
    return strtol(string, &end, 10);
}

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
        if (de->d_type != DT_DIR || !(pid = this->GetStringInteger(de->d_name)))
        {
            continue;
        }

        try {
            this->Load(pid);
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
        this->process_list[pid] = std::unique_ptr<Core::Process>(new Core::Process(pid));
        std::cout << *(this->process_list[pid]) << std::endl;
    } catch( std::runtime_error &error ) {
        std::cerr << error.what() << std::endl;
    }
}

} // End Manager
} // End LixProc
