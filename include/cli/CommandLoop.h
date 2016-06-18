#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H

namespace LixProc
{
namespace CLI
{

class CommandLoop
{
    public:
        CommandLoop(void);
        void InitMainLoop(void);

    private:
        static const std::string line_prefix;
};

} // End CLI
} // End SystemMonitor

#endif
