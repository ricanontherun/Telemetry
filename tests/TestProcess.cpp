#define CATCH_CONFIG_MAIN

#include "test_header.h"

#include <memory>
#include <unistd.h>
#include <stdexcept>
#include <sys/types.h>

#include <core/sys/SystemInfo.h>
#include <core/process/Process.h>

TEST_CASE("Telemetry::Core::Process")
{
    using Telemetry::Core::Process;

    Telemetry::SystemInfo::Capture();

    SECTION("Throws an exception when a non-existent pid is provided.")
    {
        REQUIRE_THROWS(Process(0));
    }

    pid_t current_pid = getpid();

    std::unique_ptr<Process> process(new Process(current_pid));
    
    REQUIRE(process);

    SECTION("Each Process has an executable name.")
    {
        Telemetry::Utils::Command command = process->GetCommand();
        REQUIRE(command.name.length());
    }

    SECTION("Each Process uses memory.")
    {
        REQUIRE(process->GetActualMemoryUsage() > 0.0);
    }
}
