#pragma once
#include "../pattern/pattern.h"

class CallInfo : public ICommand
{
public:
    void execute(int argc, char *argv[]);
    CallInfo(const char *name, const char *desc) : ICommand(name, desc){};
};