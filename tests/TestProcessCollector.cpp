#include "tests.h"

#include <iterator>

#include <results.h>
#include <Collectors/ProcessCollector.h>
#include <utils/shell.h>

TEST_CASE("ProcessCollector", "[ProcessCollector] [Collectors]")
{
    using Telemetry::Collectors::ProcessCollector;
    using Telemetry::Core::ProcessIterators;

    // Load() iterators must point to at least one process.
    SECTION("collect() must find at least one process.")
    {
        Telemetry::Results process_results;
        ProcessCollector collector;

        collector.collect(process_results);

        ProcessIterators iterators = process_results.GetProcessIterators();

        auto num_procs = std::distance(iterators.first, iterators.second);

        REQUIRE(num_procs >= 1);

        std::string proc_ls_output;
        Telemetry::Utils::RunInShell("ls /proc | grep \"[0-9]\" | wc -l", proc_ls_output);

        std::cout << num_procs << "\n";
        std::cout << proc_ls_output << "\n";
    }

    SECTION("Load(exe) returns a at least one process, if it exists")
    {
        // Get the pid of the tests exe, load that.
    }
}
