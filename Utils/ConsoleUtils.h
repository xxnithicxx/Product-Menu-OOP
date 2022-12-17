#pragma once

#include <iostream>
#include <string>

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers

#include "Windows.h"

enum Color
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15,
};

namespace ConsoleUtils
{
    void clearScreen();
    void changeColor(Color color);
    void highlight(std::string text);
    void gotoLine(int line);
    void clearLine(int line);
    void restoreLine(int line, std::string text);
};