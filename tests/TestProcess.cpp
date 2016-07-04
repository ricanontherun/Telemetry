#define CATCH_CONFIG_MAIN

#include "test_header.h"

#include <memory>
#include <unistd.h>
#include <stdexcept>
#include <sys/types.h>

#include <core/sys/SystemInfo.h>
#include <core/process/Process.h>

TEST_CASE("LixProc::Core::Process")
{
    LixProc::SystemInfo::Capture();
    using LixProc::Core::Process;

    SECTION("Throws an exception when a non-existent pid is provided.")
    {
        REQUIRE_THROWS(new Process(0));
    }

    // From this point on, all tests will operate on a process object
    // representing the current process.
    pid_t current_pid = getpid();

    std::unique_ptr<Process> process(new Process(current_pid));
    REQUIRE(process);

    SECTION("Each Process has an executable name.")
    {
        LixProc::Utils::Command command = process->GetCommand();
        REQUIRE(command.name.length());
    }

    SECTION("Each Process uses memory.")
    {
        REQUIRE(process->GetActualMemoryUsage() > 0.0);
        REQUIRE(process->GetRelativeMemoryUsage() > 0.0);
    }
}
