#ifndef CLI_COMMANDS_COMMAND_FACTORY_H
#define CLI_COMMANDS_COMMAND_FACTORY_H

class CommandFactory
{
    public:
        static virtual void Make(std::string concrete) = 0;
};

#endif
