#define CATCH_CONFIG_MAIN

#include <sys/types.h>
#include <unistd.h>
#include <stdexcept>

#include "test_header.h"
#include <core/process/Process.h>

TEST_CASE("LixProc::Core::Process")
{
    SECTION("Throws an exception when a non-existent pid is provided.")
    {
        REQUIRE_THROWS(new LixProc::Core::Process(0));
    }

    // From this point on, all tests will operate on a process object
    // representing the current process.

    pid_t current_pid = getpid();
    LixProc::Core::Process *process = new LixProc::Core::Process(current_pid);

    REQUIRE(process);

    SECTION("Each Process has an executable name.")
    {
        LixProc::Utils::Command command = process->GetCommand();
        REQUIRE(command.name.length());
    }

    SECTION("Each Process uses memory.")
    {
        REQUIRE(process->GetActualMemoryUsage() > 0.0);
    }

    delete process;
}
