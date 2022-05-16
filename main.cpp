#include <iostream>
#include "Commands/pattern/pattern.h"
#include "Commands/help/help.h"
#include "Commands/callInfo/callInfo.h"

void cmdSetup();

int main(int argc, char *argv[])
{
    IExecute *exec = new IExecute();
    cmdSetup();
    if (argc > 1)
    {
        ICommand *called = searchCommands(argv[1]);
        if (called == nullptr)
        {
            std::cout << "Dit command bestaat niet" << std::endl;
            exit(1);
        }

        (*exec)(called, argc, argv);
    }
    return 0;
}

void cmdSetup()
{
    ICommand *myHelp = new HelpCmd("Help", "Dit is een functie om hulp te krijgen voor andere functies");
    ICommand *callInfo = new CallInfo("Print", "Print informatie over de gegeven argumenten");
    cmdMap->push_back({"--help", myHelp});
    cmdMap->push_back({"-H", myHelp});
    cmdMap->push_back({"--call-info", callInfo});
    cmdMap->push_back({"-CI", callInfo});
}