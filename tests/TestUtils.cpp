#include "test_header.h"

#include "../core/util/str.h"

TEST_CASE("split()")
{
    SECTION("Returns an non-empty vector if at least one delimiter is present in source string.")
    {
        std::string str = "Break,This,String,Up";
        std::vector<std::string> parts = SystemMonitor::Utils::split(str, ',');

        REQUIRE(parts.size() >= 1);
    }

    SECTION("Returns a vector of empty strings if the source string contains ONLY delimiters.")
    {
        std::string str = ",,,";
        std::vector<std::string> parts = SystemMonitor::Utils::split(str, ',');

        std::vector<std::string>::iterator it;
        for ( it = parts.begin(); it != parts.end(); it++ ) {
            REQUIRE((*it).length() == 0);
        }
    }
}
