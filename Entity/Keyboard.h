#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <conio.h>
using namespace std;

#define CLEAR_KEYBUFFER         \
    while ((getchar()) != '\n') \
        ;

enum KeyPress
{
    KEY_UP = 0x48,
    KEY_DOWN = 0x50,
    KEY_LEFT = 0x4B,
    KEY_RIGHT = 0x4D,
    ESC_KEY = 0x1B,
    ENTER_KEY = 0x0D,
};

class Keyboard
{
private:
    Keyboard();
    inline static shared_ptr<Keyboard> _instance = nullptr;

public:
    static shared_ptr<Keyboard> instance();
    string getInput();
};