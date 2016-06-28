#include "test_header.h"

#include <utils/RegexMap.h>
#include <string>

TEST_CASE("RegexMap")
{
    SECTION("Test that it can set a regular expression")
    {
        RegexMap<std::string> map;
        std::string key("NAME");

        map.Set(key, "^name:[[:w:]]$");

        REQUIRE(map.KeyExists(key));
    }

    SECTION("Test that it throws an exception when testing a non-existent key")
    {
        RegexMap<std::string> map;
        std::string key = "I DONT EXIST IN THE MAP";

        REQUIRE_FALSE(map.KeyExists(key));
        REQUIRE_THROWS(map.Test(key, "This is the regex search context"));
    }

    SECTION("Test that it can test regular expressions.")
    {
        enum class Expression {
            PROCESS_NAME
        };

        RegexMap<Expression> map;

        map.Set(Expression::PROCESS_NAME, "^name:[[:w:]]+$");

        REQUIRE(map.Test(Expression::PROCESS_NAME, "name:Firefox"));
        REQUIRE_FALSE(map.Test(Expression::PROCESS_NAME, "Firefox:name"));
    }
}
