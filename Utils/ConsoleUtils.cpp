#include "ConsoleUtils.h"

void ConsoleUtils::clearScreen()
{
    system("cls");
}

void ConsoleUtils::changeColor(Color color)
{
    if (color < 0 || color > 15)
        return;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ConsoleUtils::highlight(std::string text)
{
    changeColor(Color::LIGHTRED);
    std::cout << text << std::endl;
    changeColor(Color::WHITE);
}

void ConsoleUtils::gotoLine(int line)
{
    COORD coord;
    coord.X = 0;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleUtils::clearLine(int line)
{
    gotoLine(line);
    std::cout << "                                                                                                    ";
}

void ConsoleUtils::restoreLine(int line, std::string text)
{
    gotoLine(line);
    std::cout << text;
}
