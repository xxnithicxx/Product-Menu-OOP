#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

// This is the interface for all menus
class Menu: public Object
{
public:
    virtual void show() = 0;
    virtual void handleInput(string input) = 0;
};