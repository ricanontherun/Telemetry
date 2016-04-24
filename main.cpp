#include "api/API.h"

using namespace std;

int main()
{
    API *process_api = API::Create(API::API_TYPES::PROCESS);

    delete process_api;
    return 0;
}
