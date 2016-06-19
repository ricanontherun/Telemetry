#include <iostream>
#include <string>
#include <vector>

#include <cli/CommandLoop.h>

int main()
{
    SystemMonitor::CLI::CommandLoop loop;

    loop.InitMainLoop();
}
