#include "test_header.h"

#include <iterator>

#include <manager/ProcessManager.h>

TEST_CASE("LixProc::Manager::ProcessManager")
{
    // TODO: Find a better way to get this during runtime.
    std::string test_process_name = "tests";

    using LixProc::Manager::ProcessManager;
    using LixProc::Manager::ProcessIterators;

    // Load() iterators must point to at least one process.
    SECTION("Load() must find at least one process.")
    {
        ProcessIterators iterators = ProcessManager::Load();

        REQUIRE(std::distance(iterators.first, iterators.second) >= 1);
    }

    SECTION("Load(exe) returns a at least one process, if it exists")
    {
        ProcessIterators iterators = ProcessManager::Load(test_process_name);

        REQUIRE(std::distance(iterators.first, iterators.second) >= 1);
    }
}
