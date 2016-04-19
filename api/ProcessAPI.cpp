#include "ProcessAPI.h"

#include <iostream>
#include <limits>

#include "../core/process/Process.h"

using namespace std;

ProcessAPI::ProcessAPI()
{
    this->LoadProcessList();
}

/**
 * Clean up. Free all memory take up by the list of processes.
 */
ProcessAPI::~ProcessAPI()
{
    // We create an iterator for map<uint32_t, Process *> map.
    map<uint32_t, Process *>::iterator it;

    // Iterate over the process_list and free each object.
    // TODO: Make sure we add some more validation here?
    for ( it = this->process_list.begin(); it != this->process_list.end(); it++ ) {
        delete it->second;
    }
}

void ProcessAPI::LoadProcessList()
{

    DIR *d;
    struct dirent *de;

    d = opendir("/proc");

    if (d == NULL)
    {
        closedir(d);
    }

    char *end;
    while (de = readdir(d))
    {
        long pid = strtol(de->d_name, &end, 10);
        if (de->d_type != DT_DIR || pid == 0)
        {
            continue;
        }

        this->process_list[pid] = new Process(pid);

        // If the de struct is 1) A directory and 2) has an integer name
        // , can we safely assume that it's a process directory?
        // More research is required.

        // find_task_by_pid()
        // We need a way to either acquire a process object
        // or build our own.
    }

    closedir(d);
}
