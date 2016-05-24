#define CATCH_CONFIG_MAIN

#include <sys/types.h>
#include <unistd.h>
#include <stdexcept>

#include "test_header.h"
#include "../core/process/Process.h"

TEST_CASE("Process")
{
    SECTION("Throws an exception when a non-existent pid is provided.")
    {

        bool error_thrown = false;
        try {
            Process *process = new Process(0);
        } catch( std::runtime_error &e ) {
            error_thrown = true;
        }

        REQUIRE(error_thrown == true);
    }

    // From this point on, all tests will operate on a process object
    // representing the current process.

    pid_t current_pid = getpid();
    Process *process = new Process(current_pid);

    REQUIRE(process);

    SECTION("Each Process has an executable name.")
    {
        REQUIRE(process->GetExecutable().length());
    }

    SECTION("Each Process uses memory.")
    {
        REQUIRE(process->GetActualMemoryUsage() > 0.0);
    }

    delete process;
}
