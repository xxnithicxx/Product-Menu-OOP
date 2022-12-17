#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "..\Entity\Console.h"
#include "..\Entity\Menu.h"
#include "..\Utils\ConsoleUtils.h"
#include "..\UI\DisplayMenu.h"
#include "..\UI\AddMenu.h"
using namespace std;

class MyConsole;

class MainMenu : public Menu
{
private:
    MyConsole *console;
    vector<string> lines;
    int cursor = 0;

public:
    MainMenu(MyConsole *console);
    void show();
    void handleInput(string input);
    string toString();
};