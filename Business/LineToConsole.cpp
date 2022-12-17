#include "LineToConsole.h"

Object *LineToConsole::convert(string line)
{
    return nullptr;
}

string LineToConsole::convert(Object *object)
{
    stringstream ss;
    Product *temp = dynamic_cast<Product *>(object);
    ss << setw(10) << left << temp->getId() << "|" << setw(20) << left << temp->getName() << setw(10) << left << temp->getPrice();
    return ss.str();
}

LineToConsole::LineToConsole()
{
}

shared_ptr<LineToConsole> LineToConsole::instance()
{
    if (_instance == nullptr)
    {
        LineToConsole *temp = new LineToConsole();
        _instance = shared_ptr<LineToConsole>(temp);
    }
    return _instance;
}