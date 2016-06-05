#define CATCH_CONFIG_MAIN

#include <sys/types.h>
#include <unistd.h>
#include <stdexcept>

#include "test_header.h"
#include "../core/process/Process.h"

TEST_CASE("SystemMonitor::Core::Process")
{
    SECTION("Throws an exception when a non-existent pid is provided.")
    {

        bool error_thrown = false;
        try {
            SystemMonitor::Core::Process *process = new SystemMonitor::Core::Process(0);
        } catch( std::runtime_error &e ) {
            error_thrown = true;
        }

        REQUIRE(error_thrown == true);
    }

    // From this point on, all tests will operate on a process object
    // representing the current process.

    pid_t current_pid = getpid();
    SystemMonitor::Core::Process *process = new SystemMonitor::Core::Process(current_pid);

    REQUIRE(process);

    SECTION("Each Process has an executable name.")
    {
        SystemMonitor::Core::Process::Command command = process->GetCommand();
        REQUIRE(command.executable.length());
    }

    SECTION("Each Process uses memory.")
    {
        REQUIRE(process->GetActualMemoryUsage() > 0.0);
    }

    delete process;
}
