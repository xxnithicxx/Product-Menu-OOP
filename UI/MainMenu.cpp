#include "MainMenu.h"

MainMenu::MainMenu(MyConsole *console)
{
    this->console = console;

    lines.push_back("1. Show products");
    lines.push_back("2. Add product");
    lines.push_back("3. Exit");
}

void MainMenu::show()
{
    for (int i = 0; i < lines.size(); i++)
    {
        if (i == cursor)
        {
            ConsoleUtils::highlight(lines[i]);
        }
        else
        {
            cout << lines[i] << endl;
        }
    }
}

void MainMenu::handleInput(string input)
{
    int prevCursor = cursor;

    if (input == "keyup")
    {
        cursor--;
        if (cursor < 0)
        {
            cursor = lines.size() - 1;
        }
    }
    else if (input == "keydown")
    {
        cursor++;
        if (cursor >= lines.size())
        {
            cursor = 0;
        }
    }
    else if (input == "enter")
    {
        if (cursor == 0)
        {
            console->setMenu(new DisplayMenu(console));
        }
        else if (cursor == 1)
        {
            console->setMenu(new AddMenu(console));
        }
        else if (cursor == 2)
        {
            exit(0);
        }
    }
    else if (input == "escape")
    {
        console->setMenu(nullptr);
    }

    ConsoleUtils::restoreLine(prevCursor, lines[prevCursor]);
    ConsoleUtils::gotoLine(cursor);
    ConsoleUtils::highlight(lines[cursor]);
}

string MainMenu::toString()
{
    return "Main Menu";
}