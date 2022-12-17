#include "Keyboard.h"

Keyboard::Keyboard()
{
}

shared_ptr<Keyboard> Keyboard::instance()
{
    if (_instance == nullptr)
    {
        Keyboard *temp = new Keyboard();
        _instance = shared_ptr<Keyboard>(temp);
    }
    return _instance;
}

string Keyboard::getInput()
{
    // Get key by key and return it as a string
    string input = "null";
    // fflush(stdin);
    unsigned char key = getch();
    if (key == 0xE0)
    {
        key = getch();
        switch (key)
        {
        case KEY_UP:
            input = "keyup";
            break;
        case KEY_DOWN:
            input = "keydown";
            break;
        case KEY_LEFT:
            input = "keyleft";
            break;
        case KEY_RIGHT:
            input = "keyright";
            break;
        }
    }
    else if (key == ESC_KEY)
    {
        input = "escape";
    }
    else if (key == ENTER_KEY)
    {
        input = "enter";
    }

    return input;
}