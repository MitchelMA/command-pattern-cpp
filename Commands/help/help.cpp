#include "help.h"
#include <iostream>
#include <iomanip>
void HelpCmd::execute(int argc, char *argv[])
{
    if (argc < 3)
    {
        // loop through all the commands
        auto cmdMapIt = cmdMap->cbegin();
        for (; cmdMapIt != cmdMap->cend(); ++cmdMapIt)
        {
            std::cout << "  " << std::left << std::setw(15) << cmdMapIt->first << "  -  " << cmdMapIt->second->desc << "\n";
        }
        std::cout << std::flush;
    }
    else
    {
        // print info about the specified command
        try
        {
            ICommand *helped = searchCommands(argv[2]);
            if (helped == nullptr)
            {
                std::cout << "Dit command bestaat niet" << std::endl;
                return;
            }
            std::cout << helped->desc << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}