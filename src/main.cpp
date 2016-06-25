#include <iostream>
#include <string>
#include <regex>

#include <cli/CommandLoop.h>
#include <utils/RegexMap.h>

int main(int argc, char **argv)
{
    RegexMap<std::string> map;
    std::string expression("asdasd");

    map.Set("key", expression);
    map.Set("key", expression);
}
