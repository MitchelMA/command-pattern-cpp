#pragma once
#include <string>
#include <vector>
#include <utility>

typedef struct ICommand
{
    const char *name;
    const char *desc;
    virtual void execute(int argc, char *argv[]);
    ICommand(const char *name, const char *desc);
} ICommand;

typedef struct IExecute
{
    void operator()(ICommand *command, int argc, char *argv[]);
    void execute(ICommand *command, int argc, char *argv[]);
} IExecute;

// command map
extern std::vector<std::pair<std::string, ICommand *>> *cmdMap;
ICommand *searchCommands(std::string tKey);