#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "..\Entity\Menu.h"
#include "..\Entity\Console.h"
#include "..\Utils\ConsoleUtils.h"
using namespace std;

class MyConsole;

class AddMenu : public Menu
{
private:
    MyConsole* console;
    string name, price;

public:
    AddMenu(MyConsole* console);
    void show();
    void handleInput(string input);
    string toString();
};