#include <string.h>

#include "Process.h"
#include "../util/str.h"

using namespace std;

const string Process::PD_STATM   = "statm";
const string Process::PD_CMDLINE = "cmdline";

bool Process::LoadProcessName()
{
    string dir = this->process_base_path + "/" + Process::PD_CMDLINE;
    char buf[BUFSIZ];

    // ENC: GetFile(file_name, mode)
    FILE *fp = fopen(dir.c_str(), "r");

    if ( fp == NULL ) {
        // TODO: What is the appropriate action to take here?
        // I would say straight remove this object from the parent thinger.

        fclose(fp);
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


    // Split the 
    string mem_str(buf);
    vector<string> mem_parts = split(mem_str, ' ');

     

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
