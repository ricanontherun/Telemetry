#include <iostream>
#include <limits>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <stdint.h>
#include <map>
#include <unistd.h>

#include "API.h"
#include "ProcessAPI.h"
#include "../core/sys/SystemInfo.h"

std::string ProcessAPI::proc_root = "/proc/";

ProcessAPI::ProcessAPI()
{
    this->LoadProcessList();
}

ProcessAPI::~ProcessAPI()
{
    // We create an iterator for map<uint32_t, Process *> map.
    std::map<uint32_t, Process *>::iterator it;

    // Iterate over the process_list and free each object.
    // TODO: Make sure we add some more validation here?
    for (it = this->process_list.begin(); it != this->process_list.end(); it++)
    {
        delete it->second;
    }
}

/*
|--------------------------------------------------
| Private
|--------------------------------------------------
*/

uint64_t ProcessAPI::GetStringInteger(char *string)
{
    char *end;
    return strtol(string, &end, 10);
}

void ProcessAPI::LoadProcessList()
{

    DIR *d;
    struct dirent *de;

    d = opendir(ProcessAPI::proc_root.c_str());

    if (d == NULL)
    {
        closedir(d);
    }

    uid_t uid = getuid();
    gid_t gid = getgid();

    struct stat info;
    int stat_i;
    uint64_t pid;

    SystemInfo::Capture();

    while (de = readdir(d))
    {
        if (de->d_type != DT_DIR || !(pid = this->GetStringInteger(de->d_name)))
        {
            continue;
        }

        std::string dir_name(de->d_name);
        std::string full_process_path = ProcessAPI::proc_root + dir_name;

        stat_i = stat(full_process_path.c_str(), &info);
        if (stat_i == -1)
        {
            // TODO: Determine appropriate action. If the file doesn't exist,
            // that probably shouldn't be an error. Else, write to a log?
            std::cout << strerror(errno) << std::endl;
            continue;
        }

        // Are we the owner of the process?
        if (uid != info.st_uid || gid != info.st_gid)
        {
            continue;
        }

        // Add it to the process list. Instantiating the process object
        // will fill it with relevant data.
        this->process_list[pid] = new Process(pid);

        std::cout << *(this->process_list[pid]) << std::endl;
    }

    closedir(d);
}
