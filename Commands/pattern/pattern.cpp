#include "pattern.h"
#include <iostream>
#include <cstring>

void ICommand::execute(int argc, char *argv[])
{
    std::cout << "Dit is een fallback op de execute method.\nAls je dit ziet, is de bedoelde method nog niet geimplementeerd!" << std::endl;
}
ICommand::ICommand(const char *name, const char *desc)
{
    this->name = name;
    this->desc = desc;
}

void IExecute::operator()(ICommand *command, int argc, char *argv[])
{
    command->execute(argc, argv);
};
void IExecute::execute(ICommand *command, int argc, char *argv[])
{
    (*this)(command, argc, argv);
}

// implementation of the cmdMap
std::vector<std::pair<std::string, ICommand *>> *cmdMap = new std::vector<std::pair<std::string, ICommand *>>();
ICommand *searchCommands(std::string tKey)
{
    auto it = cmdMap->cbegin();
    for (; it != cmdMap->cend(); ++it)
    {
        if (strcmp(tKey.c_str(), it->first.c_str()) == 0)
        {
            return const_cast<ICommand *>(it->second);
        }
    }
    return (ICommand *)nullptr;
}