#include <iostream>
#include <string>
#include <regex>

#include <cli/CommandLoop.h>

int main(int argc, char **argv)
{
    std::regex r_all("^all$");
    std::regex r_name("^name:[[:w:]]+$");

    LixProc::CLI::CommandLoop loop;
    loop.InitMainLoop();
}
