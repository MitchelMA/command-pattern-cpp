#include "callInfo.h"
#include <iostream>

void CallInfo::execute(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        if (i == 0)
        {
            std::cout << "Programma naam (.exe): " << argv[i] << std::endl;
        }
        else if (i == 1)
        {
            std::cout << "Command waarmee opgeroepen: " << argv[i] << std::endl;
        }
        else
        {
            std::cout << "Overig argument: " << argv[i] << std::endl;
        }
    }
}