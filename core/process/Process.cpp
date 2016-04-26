#include "Process.h"

#include <string.h>
#include <stdio.h>

#include "../util/str.h"
#include "../util/file.h"

using namespace std;

const string Process::PD_STATM   = "statm";
const string Process::PD_CMDLINE = "cmdline";

bool Process::LoadProcessName()
{
    string dir = this->process_base_path + "/" + Process::PD_CMDLINE;
    char buf[BUFSIZ];

    const char *mode = "r";
    FILE *fp = GetFile(dir.c_str(), mode);

    if ( fp == NULL ) {
        return false;
    }
    // END GetFile

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
    this->memory = new ProcessMemory;

    // TODO: Can we somehow encapsulate this logic?
    // It is used in both LoadProcessMemory AND LoadProcessName...
    string dir = this->process_base_path + "/" + Process::PD_STATM;

    char buf[BUFSIZ];
    FILE *fp = fopen(dir.c_str(), "r");

    if ( fp == NULL ) {
        fclose(fp);
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
    string memory_string(buf);
    vector<string> memory_vector = split(memory_string, ' ');

    // TODO: Add some validation, in case split fails.
    // Assign to this->memory
    this->memory->size      = atoi(memory_vector[0].c_str());
    this->memory->resident  = atoi(memory_vector[1].c_str());
    this->memory->share     = atoi(memory_vector[2].c_str());
    this->memory->text      = atoi(memory_vector[3].c_str());
    this->memory->lib       = atoi(memory_vector[4].c_str());
    this->memory->data      = atoi(memory_vector[5].c_str());
    this->memory->dirty     = atoi(memory_vector[6].c_str());

    return true;
}

bool Process::LoadProcessData()
{
    this->LoadProcessName();

    this->LoadProcessMemory();
}

Process::Process(uint32_t pid)
{
    this->pid = pid;
    this->process_base_path = "/proc/" + to_string(this->pid);

    this->LoadProcessData();
}

Process::~Process() {
    delete this->memory;
}
