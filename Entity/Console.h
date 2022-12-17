#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Keyboard.h"
#include "..\Business\ProductDatabase.h"
#include "..\UI\MainMenu.h"
#include "..\Utils\ConsoleUtils.h"
using namespace std;

class MyConsole 
{
private:
    Menu *menu; // State pattern
    shared_ptr<Keyboard> keyboard;
    ProductDatabase *productDatabase;
    bool changeConsole;

public:
    void setMenu(Menu *menu);
    ProductDatabase *getProductDatabase();

public:
    MyConsole(ProductDatabase *productDatabase);
    void show();
    void run();
};