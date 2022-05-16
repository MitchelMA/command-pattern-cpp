#pragma once
#include "../pattern/pattern.h"

class HelpCmd : public ICommand
{
public:
    void execute(int argc, char *argv[]);
    HelpCmd(const char *name, const char *desc) : ICommand(name, desc){};
};