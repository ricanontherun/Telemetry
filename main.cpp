#include <sys/sysinfo.h>
#include "api/API.h"

int main()
{
    API *process_api = API::Instance(API::API_TYPES::PROCESS);

    delete process_api;
    return 0;
}
